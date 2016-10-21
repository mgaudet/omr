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

#include <stdint.h> // for int32_t
#include "il/Node.hpp" // for Node, vcount_t
#include "infra/Link.hpp" // for TR_Link, etc
#include "infra/List.hpp" // for TR_Queue, etc
#include "optimizer/OptimizationManager.hpp" // for OptimizationManager
#include "optimizer/LoopCanonicalizer.hpp" // for TR_LoopTransformer

class TR_BitVector;
class TR_RegionStructure;
class TR_Structure;
class TR_StructureSubGraphNode;
namespace TR {
class Block;
}
namespace TR {
class CFGEdge;
}
namespace TR {
class Optimization;
}
namespace TR {
class TreeTop;
}
template <class T> class TR_Stack;

#define MAX_NODE_THRESHOLD_FOR_REPLICATION 200
#define MAX_REPLICATION_GROWTH_FACTOR 1.3 // 33% of the loop
#define MAX_REPLICATION_GROWTH_SIZE 70
#define MAX_REPLICATION_NESTING_DEPTH 2
// old thresholds
//#define BLOCK_THRESHOLD 0.02
//#define SEED_THRESHOLD  0.02
#define BLOCK_THRESHOLD 0.15
#define SEED_THRESHOLD 0.15

#define BLOCK_THRESHOLD_PERCENTAGE (BLOCK_THRESHOLD * 100)

/*
 * Prototype of frequency based loop replication
 *    - attempts to transform loops by removing cold
 *    paths out of the loop [by tail duplication] into
 *    an outer loop. the inner loop consists of only
 *    the most frequently executed code
 */

enum loopType { doWhile, whileDo };
enum listType { common, cloned };

class TR_LoopReplicator : public TR_LoopTransformer {
public:
    TR_LoopReplicator(TR::OptimizationManager* manager);
    static TR::Optimization* create(TR::OptimizationManager* manager)
    {
        return new (manager->allocator()) TR_LoopReplicator(manager);
    }

    virtual int32_t perform();

    // per loop structures
    struct BlockEntry : public TR_Link<BlockEntry> {
        BlockEntry()
            : _nonLoop(false)
        {
        }

        TR::Block* _block;
        // been visited before in another
        // loop
        bool _nonLoop;
    };
    struct EdgeEntry : public TR_Link<EdgeEntry> {
        EdgeEntry()
            : _removeOnly(false)
        {
        }
        TR::CFGEdge* _edge;
        bool _removeOnly;
    };

    struct LoopInfo : public TR_Link<LoopInfo> {
        TR_LinkHeadAndTail<BlockEntry> _nodesCommon;
        TR_LinkHeadAndTail<BlockEntry> _blocksCloned;
        TR_LinkHead<EdgeEntry> _removedEdges;

        TR::Block* _outerHeader;
        int32_t _regionNumber;
        bool _replicated;
        TR_RegionStructure* _region;
        int32_t _seedFreq;
    };

    // main routines
    //
    int32_t perform(TR_Structure* str);
    bool isWellFormedLoop(TR_RegionStructure* region, TR_Structure* condBlock);
    int32_t replicateLoop(TR_RegionStructure* region, TR_StructureSubGraphNode* branchNode);

    // helper routines
    //
    int32_t countChildren(TR::Node* node, vcount_t visitCount);
    void gatherRestOfLoop(TR_RegionStructure* region, TR_Queue<TR::Block>* bq);
    void gatherRestOfLoop(TR_RegionStructure* region, TR::Block* b, TR_Queue<TR::Block>& n);
    bool heuristics(LoopInfo* lInfo);
    void logTrace(LoopInfo* lInfo);
    // overload; dumb heuristics for testing at count=0
    bool heuristics(LoopInfo* lInfo, bool dumb);
    TR::Block* nextCandidate(TR::Block* X, TR_RegionStructure* region, bool doSucc);
    void processBlock(TR::Block* X, TR_RegionStructure* region, LoopInfo* lInfo);
    bool computeWeight(TR::CFGEdge* edge);
    TR::Block* bestSuccessor(TR_RegionStructure* r, TR::Block* b, TR::CFGEdge** edge);
    bool gatherBlocksToBeCloned(LoopInfo* lInfo);
    void doTailDuplication(LoopInfo* lInfo);
    void addBlocksAndFixEdges(LoopInfo* lInfo);
    TR::Block* createEmptyGoto(TR::Block* s, TR::Block* d, bool redirect = false);
    TR::TreeTop* findEndTreeTop(TR_RegionStructure* r);
    LoopInfo* findLoopInfo(int32_t regionNumber);
    BlockEntry* searchList(TR::Block* block, listType lT, LoopInfo* lInfo);
    void modifyLoops();
    TR_StructureSubGraphNode* findNodeInHierarchy(TR_RegionStructure* r, int32_t num);
    void nextSuccessor(TR_RegionStructure* r, TR::Block** cand, TR::CFGEdge** edge);
    void fixUpLoopEntry(LoopInfo* lInfo, TR::Block* loopHeader);
    bool isBackEdgeOrLoopExit(TR::CFGEdge* e, TR_RegionStructure* region, bool testSGraph = false);
    int32_t getSeedFreq(TR_RegionStructure* r);
    int32_t getBlockFreq(TR::Block* X);
    int32_t getScaledFreq(TR_ScratchList<TR::Block>& blocks, TR::Block* X);
    bool checkForSuccessor(TR::Block* b1, TR::Block* b2);

    void calculateBlockWeights(TR_RegionStructure* region);
    int32_t deriveFrequencyFromPreds(TR_StructureSubGraphNode* curNode, TR_RegionStructure* region);
    bool predecessorsNotYetVisited(TR_RegionStructure* r, TR_StructureSubGraphNode* curNode);

    bool isSwitchBlock(TR::Block* b);
    void gatherTargets(TR_Queue<TR::Block>& q, TR_Queue<TR::Block>& sn, LoopInfo* l);

    bool checkInnerLoopFrequencies(TR_RegionStructure* region, LoopInfo* lInfo);
    bool shouldReplicateWithHotInnerLoops(
        TR_RegionStructure* region, LoopInfo* lInfo, TR_ScratchList<TR::Block>* hotInnerLoopHeaders);
    // current loopinfo
    LoopInfo* _curLoopInfo;

private:
    bool _haveProfilingInfo;
    int32_t _nodeCount;
    // map real blocks -> clones
    TR::Block** _blockMapper;
    // map block numbers -> blocks
    TR::Block** _blocksInCFG;
    TR_Queue<TR::Block> _blocksCloned;
    int32_t _nodesInCFG;
    loopType _loopType;
    TR_LinkHead<LoopInfo> _loopInfo;
    TR_BitVector* _blocksVisited;
    int32_t* _seenBlocks;
    int32_t* _blockWeights;
    TR_Stack<TR::Block*>* _bStack;
    TR::TreeTop* _switchTree;
    int32_t _maxNestingDepth;
};
