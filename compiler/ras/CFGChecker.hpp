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

#ifndef CFGCHECK_INCL
#define CFGCHECK_INCL

#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for int32_t
#include "env/TRMemory.hpp" // for TR_Memory, etc
#include "infra/BitVector.hpp" // for TR_BitVector
#include "infra/Cfg.hpp"

class TR_Debug;
namespace TR {
class Block;
}
namespace TR {
class Node;
}
namespace TR {
class ResolvedMethodSymbol;
}
namespace TR {
class TreeTop;
}

/// This class can be used to check if the CFG is correct. The check is
/// performed in two distinct steps.
///
/// The first step involves checking the successors list of each basic block in
/// the CFG and verifying whether the edges to the successors are correct. This
/// involves checking the last IL instruction in each basic block and comparing
/// its targets with the successors of the basic block in the CFG.
///
/// The second step performs a consistency check for all basic blocks in the
/// CFG; this involves checking if a basic block BB1 is in the successors list
/// of basic block BB2, is BB2 in the predecessors list of BB1 or not.
///
/// Note that these two checks together are sufficient to show that the CFG
/// is correct or otherwise.
///
class TR_CFGChecker {
public:
    TR_ALLOC(TR_Memory::CFGChecker)

    TR_CFGChecker(TR::ResolvedMethodSymbol*, TR_Debug*);
    TR_CFGChecker(TR::CFG* cfg, TR::FILE* pOutFile)
        : _cfg(cfg)
        , _fe(cfg->comp()->fe())
        , _outFile(pOutFile){};

    void check();

protected:
    void markCFGNodes();
    bool arrangeBlocksInProgramOrder();
    bool areSuccessorsCorrect(int32_t);
    bool equalsAnyChildOf(TR::TreeTop*, TR::Node*);
    int32_t getNumUniqueCases(TR::Node*);
    void performCorrectnessCheck();
    void performConsistencyCheck();
    bool isConsistent(TR::Block*);
    bool checkForUnreachableCycles();

    TR::CFG* _cfg;
    TR::Block** _blocksInProgramOrder;
    int32_t _numBlocks;
    int32_t _numRealBlocks;
    bool _successorsCorrect;
    bool _isCFGConsistent;
    TR_BitVector _blockChecklist;
    TR::FILE* _outFile;
    TR_FrontEnd* _fe;
};

#endif
