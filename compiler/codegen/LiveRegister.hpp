/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#ifndef LIVEREGISTER_INCL
#define LIVEREGISTER_INCL

#include <stddef.h> // for NULL
#include <stdint.h> // for uint64_t
#include "codegen/RegisterConstants.hpp" // for TR_RegisterMask
#include "compile/Compilation.hpp" // for Compilation
#include "control/Options.hpp"
#include "control/Options_inlines.hpp"
#include "env/CompilerEnv.hpp"
#include "env/TRMemory.hpp" // for TR_Memory, etc
#include "infra/Assert.hpp" // for TR_ASSERT
#include "ras/Debug.hpp" // for TR_DebugBase

namespace TR {
class CodeGenerator;
}
namespace TR {
class Node;
}
namespace TR {
class RealRegister;
}
namespace TR {
class Register;
}
namespace TR {
class RegisterPair;
}

// Live register information, used to determine live range information for
// virtual registers
//
class TR_LiveRegisterInfo {

public:
    TR_ALLOC(TR_Memory::LiveRegisterInfo)

    TR_LiveRegisterInfo(TR::Compilation* compilation)
        : _compilation(compilation)
    {
    }

    void initialize(TR::Register* reg)
    {
        _register = reg;
        _node = NULL;
        _numOwningNodes = 0;
        _interference = 0;
        _association = 0;
    }

    int32_t getNodeCount() { return _numOwningNodes; }
    void setNodeCount(int32_t n) { _numOwningNodes = n; }
    int32_t incNodeCount() { return ++_numOwningNodes; }
    int32_t decNodeCount()
    {
        TR_ASSERT(_numOwningNodes > 0, "Bad node count");
        return --_numOwningNodes;
    }

#if defined(TR_TARGET_POWER)
    uint64_t getAssociation()
    {
        return _association;
    }
#else
    uint32_t getAssociation()
    {
        return _association;
    }
#endif

#if defined(TR_TARGET_POWER)
    uint64_t setAssociation(uint64_t realRegMask, TR::Compilation* c)
#else
    uint32_t setAssociation(TR_RegisterMask realRegMask, TR::Compilation* c)
#endif
    {
        if (TR::Compiler->target.cpu.isX86())
            _association &= 0x80000000;
        else
            _association = 0;

        if (realRegMask)
            _association |= realRegMask;

        return _association;
    }

#if defined(TR_TARGET_POWER)
    uint64_t removeAssociation(TR::Compilation* compilation, TR_RegisterMask realRegMask)
#else
    uint32_t removeAssociation(TR::Compilation* compilation, TR_RegisterMask realRegMask)
#endif
    {
        if (realRegMask && (_association & realRegMask)) {
            if (TR::Compiler->target.cpu.isX86())
                _association &= 0x80000000;
            else
                _association = 0;
        }
        return _association;
    }

    void addByteRegisterAssociation() { _association |= 0x80000000; }

    TR_LiveRegisterInfo* getNext() { return _next; }
    TR_LiveRegisterInfo* getPrev() { return _prev; }

    void setNext(TR_LiveRegisterInfo* n) { _next = n; }
    void setPrev(TR_LiveRegisterInfo* p) { _prev = p; }

    TR::Register* getRegister() { return _register; }
    TR::Node* getNode() { return _node; }

    void setNode(TR::Node* n)
    {
        if (comp()->getOptions()->getTraceCGOption(TR_TraceCGEvaluation)) {
            getDebug()->printNodeEvaluation(n, "<- ", _register);
        }
        _node = n;
    }

    void addToList(TR_LiveRegisterInfo*& head)
    {
        _next = head;
        _prev = NULL;
        if (head)
            head->_prev = this;
        head = this;
    }

    void removeFromList(TR_LiveRegisterInfo*& head)
    {
        if (_prev)
            _prev->_next = _next;
        else
            head = _next;
        if (_next)
            _next->_prev = _prev;
    }

#if defined(TR_TARGET_POWER)
    uint64_t getInterference()
    {
        return _interference;
    }
    void addInterference(uint64_t i) { _interference |= i; }
#else
    uint32_t getInterference()
    {
        return _interference;
    }
    void addInterference(uint32_t i) { _interference |= i; }
#endif
    void addByteRegisterInterference()
    {
        if (!(_association & 0x80000000))
            _interference |= 0x80000000;
    }

    TR::Compilation* comp() { return _compilation; }
    TR::CodeGenerator* cg() { return _compilation->cg(); }
    TR_Debug* getDebug() { return comp()->getDebug(); }

private:
    TR_LiveRegisterInfo* _prev; // Local live register chain
    TR_LiveRegisterInfo* _next;

    TR::Compilation* _compilation; // For debugging
    TR::Register* _register; // For debugging
    TR::Node* _node; // For debugging

#if defined(TR_TARGET_POWER)
    uint64_t _interference; // Real registers that interfere with this register
#else
    uint32_t _interference; // Real registers that interfere with this register
#endif

#if defined(TR_TARGET_POWER)
    uint64_t _association; // The real register associated with this register
#else
    uint32_t _association; // The real register associated with this register
#endif

    int32_t _numOwningNodes; // # of nodes holding this register
};

// Information about live virtual registers
//
class TR_LiveRegisters {

public:
    TR_ALLOC(TR_Memory::LiveRegisters)

    TR_LiveRegisters(TR::Compilation* comp)
        : _compilation(comp)
        , _head(NULL)
        , _pool(NULL)
        , _numLiveRegisters(0)
    {
    }

    TR_LiveRegisterInfo* addRegister(TR::Register* reg, bool updateInterferences = true);
    TR_LiveRegisterInfo* addRegisterPair(TR::RegisterPair* reg);

    void setAssociation(TR::Register* reg, TR::RealRegister* realReg);
    void setByteRegisterAssociation(TR::Register* reg);

    void stopUsingRegister(TR::Register* reg);
    void registerIsDead(TR::Register* reg, bool updateInterferences = true);
    void removeRegisterFromLiveList(TR::Register* reg);

    static void moveRegToList(TR_LiveRegisters* from, TR_LiveRegisters* to, TR::Register* reg);

    TR_LiveRegisterInfo* getFirstLiveRegister() { return _head; }

    int32_t getNumberOfLiveRegisters() { return _numLiveRegisters; }
    int32_t decNumberOfLiveRegisters() { return _numLiveRegisters--; }

    TR::Compilation* comp() { return _compilation; }
    TR::CodeGenerator* cg() { return _compilation->cg(); }
    TR_Debug* getDebug() { return _compilation->getDebug(); }

private:
    TR::Compilation* _compilation;
    TR_LiveRegisterInfo* _head;
    TR_LiveRegisterInfo* _pool;
    int32_t _numLiveRegisters;
};

#endif
