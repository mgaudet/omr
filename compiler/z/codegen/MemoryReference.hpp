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

#ifndef TR_MEMORYREFERENCE_INCL
#define TR_MEMORYREFERENCE_INCL

#include "codegen/OMRMemoryReference.hpp"

#include <stddef.h> // for NULL
#include <stdint.h> // for int32_t
#include "codegen/Snippet.hpp" // for Snippet

class TR_StorageReference;
namespace TR {
class SymbolReference;
}
namespace TR {
class CodeGenerator;
}
namespace TR {
class Node;
}
namespace TR {
class Register;
}

namespace TR {

class OMR_EXTENSIBLE MemoryReference : public OMR::MemoryReferenceConnector {
public:
    MemoryReference(TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(cg)
    {
    }

    MemoryReference(TR::Register* br, int32_t disp, TR::CodeGenerator* cg, const char* name = NULL)
        : OMR::MemoryReferenceConnector(br, disp, cg, name)
    {
    }

    MemoryReference(TR::Register* br, int32_t disp, TR::SymbolReference* symRef, TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(br, disp, symRef, cg)
    {
    }

    MemoryReference(TR::Register* br, TR::Register* ir, int32_t disp, TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(br, ir, disp, cg)
    {
    }

    MemoryReference(int32_t disp, TR::CodeGenerator* cg, bool isConstantDataSnippet = false)
        : OMR::MemoryReferenceConnector(disp, cg, isConstantDataSnippet)
    {
    }

    MemoryReference(TR::Node* rootLoadOrStore, TR::CodeGenerator* cg, bool canUseRX = false,
        TR_StorageReference* storageReference = NULL)
        : OMR::MemoryReferenceConnector(rootLoadOrStore, cg, canUseRX, storageReference)
    {
    }

    MemoryReference(TR::Node* addressTree, bool canUseIndex, TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(addressTree, canUseIndex, cg)
    {
    }

    MemoryReference(TR::Node* node, TR::SymbolReference* symRef, TR::CodeGenerator* cg,
        TR_StorageReference* storageReference = NULL)
        : OMR::MemoryReferenceConnector(node, symRef, cg, storageReference)
    {
    }

    MemoryReference(TR::Snippet* s, TR::CodeGenerator* cg, TR::Register* base, TR::Node* node)
        : OMR::MemoryReferenceConnector(s, cg, base, node)
    {
    }

    MemoryReference(TR::Snippet* s, TR::Register* indx, int32_t disp, TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(s, indx, disp, cg)
    {
    }

    MemoryReference(MemoryReference& mr, int32_t n, TR::CodeGenerator* cg)
        : OMR::MemoryReferenceConnector(mr, n, cg)
    {
    }
};
}

#endif
