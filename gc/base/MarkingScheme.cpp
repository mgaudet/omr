/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 1991, 2016
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
 ******************************************************************************/

#include "omrcfg.h"
#include "omr.h"
#include "ModronAssertions.h"

#include <string.h>

#include "CollectorLanguageInterface.hpp"
#include "EnvironmentBase.hpp"
#include "GCExtensionsBase.hpp"
#include "Heap.hpp"
#include "MarkMap.hpp"
#include "MarkingScheme.hpp"
#include "Task.hpp"
#include "WorkPackets.hpp"
#if defined(OMR_GC_MODRON_CONCURRENT_MARK)
#include "WorkPacketsConcurrent.hpp"
#endif /* defined(OMR_GC_MODRON_CONCURRENT_MARK) */
#include "WorkPacketsStandard.hpp"

/**
 * Allocate and initialize a new instance of the receiver.
 * @return a new instance of the receiver, or NULL on failure.
 */
MM_MarkingScheme* MM_MarkingScheme::newInstance(MM_EnvironmentBase* env)
{
    MM_MarkingScheme* markingScheme;

    markingScheme = (MM_MarkingScheme*)env->getForge()->allocate(
        sizeof(MM_MarkingScheme), MM_AllocationCategory::FIXED, OMR_GET_CALLSITE());
    if (markingScheme) {
        new (markingScheme) MM_MarkingScheme(env);
        if (!markingScheme->initialize(env)) {
            markingScheme->kill(env);
            markingScheme = NULL;
        }
    }

    return markingScheme;
}

/**
 * Free the receiver and all associated resources.
 */
void MM_MarkingScheme::kill(MM_EnvironmentBase* env)
{
    tearDown(env);
    env->getForge()->free(this);
}

/**
 * Initialize the receivers internal structures and resources.
 * @return true if initialization is successful, false otherwise.
 */
bool MM_MarkingScheme::initialize(MM_EnvironmentBase* env)
{
    _markMap = MM_MarkMap::newInstance(env, _extensions->heap->getMaximumPhysicalRange());

    if (!_markMap) {
        goto error_no_memory;
    }

    _workPackets = createWorkPackets(env);
    if (NULL == _workPackets) {
        goto error_no_memory;
    }

    return true;

error_no_memory:
    return false;
}

/**
 * Free the receivers internal structures and resources.
 */
void MM_MarkingScheme::tearDown(MM_EnvironmentBase* env)
{
    if (_markMap) {
        _markMap->kill(env);
        _markMap = NULL;
    }

    if (_workPackets) {
        _workPackets->kill(env);
        _workPackets = NULL;
    }
}

/**
 * Adjust internal structures to reflect the change in heap size.
 *
 * @param size The amount of memory added to the heap
 * @param lowAddress The base address of the memory added to the heap
 * @param highAddress The top address (non-inclusive) of the memory added to the heap
 * @return true if operation completes with success
 */
bool MM_MarkingScheme::heapAddRange(
    MM_EnvironmentBase* env, MM_MemorySubSpace* subspace, uintptr_t size, void* lowAddress, void* highAddress)
{
    bool result = true;
    /* Record the range in which valid objects appear */
    _heapBase = _extensions->heap->getHeapBase();
    _heapTop = _extensions->heap->getHeapTop();

    if (result) {
        result = _markMap->heapAddRange(env, size, lowAddress, highAddress);
    }
    return result;
}

/**
 * Adjust internal structures to reflect the change in heap size.
 *
 * @param size The amount of memory added to the heap
 * @param lowAddress The base address of the memory added to the heap
 * @param highAddress The top address (non-inclusive) of the memory added to the heap
 * @param lowValidAddress The first valid address previous to the lowest in the heap range being removed
 * @param highValidAddress The first valid address following the highest in the heap range being removed
 * @return true if operation completes with success
 */
bool MM_MarkingScheme::heapRemoveRange(MM_EnvironmentBase* env, MM_MemorySubSpace* subspace, uintptr_t size,
    void* lowAddress, void* highAddress, void* lowValidAddress, void* highValidAddress)
{
    bool result = true;
    /* Record the range in which valid objects appear */
    _heapBase = _extensions->heap->getHeapBase();
    _heapTop = _extensions->heap->getHeapTop();

    if (result) {
        _markMap->heapRemoveRange(env, size, lowAddress, highAddress, lowValidAddress, highValidAddress);
    }
    return result;
}

/****************************************
 * Runtime initialization
 ****************************************
 */
void MM_MarkingScheme::masterSetupForGC(MM_EnvironmentBase* env)
{
    /* Initialize the marking stack */
    _workPackets->reset(env);

    _extensions->collectorLanguageInterface->markingScheme_masterSetupForGC(env);
}

/**
 * Set up the marking scheme for marking the heap in preparation for walking the heap.
 * This should be called in place of masterSetupForGC if no actual garbage collection
 * is to take place.
 *
 * @parm[in] env the current environment
 */
void MM_MarkingScheme::masterSetupForWalk(MM_EnvironmentBase* env)
{
    /* Initialize the marking stack */
    _workPackets->reset(env);

    _extensions->collectorLanguageInterface->markingScheme_masterSetupForWalk(env);
}

void MM_MarkingScheme::masterCleanupAfterGC(MM_EnvironmentBase* env)
{
    _extensions->collectorLanguageInterface->markingScheme_masterCleanupAfterGC(env);
}

void MM_MarkingScheme::workerSetupForGC(MM_EnvironmentBase* env) { env->_workStack.reset(env, _workPackets); }

/****************************************
 * Marking Helpers
 ****************************************
 */

/**
 * External access to inlined method isMarked
 */
bool MM_MarkingScheme::isMarkedOutline(omrobjectptr_t objectPtr) { return isMarked(objectPtr); }

bool MM_MarkingScheme::markObjectNoCheck(MM_EnvironmentBase* env, omrobjectptr_t objectPtr, bool leafType)
{
    return inlineMarkObjectNoCheck(env, objectPtr, leafType);
}

bool MM_MarkingScheme::markObject(MM_EnvironmentBase* env, omrobjectptr_t objectPtr, bool leafType)
{
    return inlineMarkObject(env, objectPtr, leafType);
}

/**************************************************************************
 * name        -  numMarkBitsInRange
 *
 * description -  Determine number of mark bits for specified heap range
 *
 *
 * parameters  - heapBase - base of region of heap whoose mark bits are to be
 * 						    counted
 * 			     heapTop  - top of region of heap whoose mark bits to be counted
 *
 * return      - the number of bytes worth of mark bits for specified heap
 * 				 range
 * *************************************************************************/
uintptr_t MM_MarkingScheme::numMarkBitsInRange(MM_EnvironmentBase* env, void* heapBase, void* heapTop)
{
    return _markMap->numberBitsInRange(env, heapBase, heapTop);
}

/**************************************************************************
 * name        -  setMarkBitsInRange
 *
 * description -  Set all mark bits for specified heap range either ON or OFF
 *
 *
 * parameters  - heapBase - base of region of heap whoose mark bits are to be set
 * 			     heapTop  - top of region of heap whoose mark bits to be set
 * 				 clear 	  - if TRUE set BITS OFF; otherwise set bits ON
 *
 * return      - the amount of memory actually cleard
 * *************************************************************************/
uintptr_t MM_MarkingScheme::setMarkBitsInRange(MM_EnvironmentBase* env, void* heapBase, void* heapTop, bool clear)
{
    return _markMap->setBitsInRange(env, heapBase, heapTop, clear);
}

/****************************************
 * Scanning
 ****************************************
 */

/**
 * Scan until there are no more work packets to be processed.
 * @note This is a joining scan: a thread will not exit this method until
 * all threads have entered and all work packets are empty.
 */
void MM_MarkingScheme::completeScan(MM_EnvironmentBase* env)
{
    omrobjectptr_t objectPtr = NULL;
    MM_WorkPackets* packets = getWorkPackets();

    do {
        while (NULL != (objectPtr = (omrobjectptr_t)env->_workStack.pop(env))) {
            scanObject(env, objectPtr, MM_CollectorLanguageInterface::SCAN_REASON_PACKET);
        }
    } while (packets->handleWorkPacketOverflow(env));
}

/****************************************
 * Marking Core Functionality
 ****************************************/

/**
 *  Initialization for Mark
 *  Actual startup for Mark procedure
 *  @param[in] env - passed Environment
 *  @param[in] initMarkMap instruct should mark map be initialized too
 */
void MM_MarkingScheme::markLiveObjectsInit(MM_EnvironmentBase* env, bool initMarkMap)
{
    workerSetupForGC(env);

    if (initMarkMap) {
        _markMap->initializeMarkMap(env);
        env->_currentTask->synchronizeGCThreads(env, UNIQUE_ID);
    }
}

/**
 *  Mark Roots
 *  Create Root Scanner and Mark all roots including classes and classloaders if dynamic class unloading is enabled
 *  @param[in] env - passed Environment
 *  @param[in] shouldScan instruct should scanning also be active while roots are marked
 */
void MM_MarkingScheme::markLiveObjectsRoots(MM_EnvironmentBase* env)
{
    _extensions->collectorLanguageInterface->markingScheme_scanRoots(env);
}

void MM_MarkingScheme::markLiveObjectsScan(MM_EnvironmentBase* env) { completeMarking(env); }

void MM_MarkingScheme::completeMarking(MM_EnvironmentBase* env)
{
    completeScan(env);

    _extensions->collectorLanguageInterface->markingScheme_completeMarking(env);
}

/**
 *  Final Mark services including scanning of Clearables
 *  @param[in] env - passed Environment
 */
void MM_MarkingScheme::markLiveObjectsComplete(MM_EnvironmentBase* env)
{
    _extensions->collectorLanguageInterface->markingScheme_markLiveObjectsComplete(env);
}

MM_WorkPackets* MM_MarkingScheme::createWorkPackets(MM_EnvironmentBase* env)
{
    MM_WorkPackets* workPackets = NULL;

#if defined(OMR_GC_MODRON_CONCURRENT_MARK)
    if (_extensions->concurrentMark) {
        workPackets = MM_WorkPacketsConcurrent::newInstance(env);
    } else
#endif /* defined(OMR_GC_MODRON_CONCURRENT_MARK) */
    {
        workPackets = MM_WorkPacketsStandard::newInstance(env);
    }

    return workPackets;
}
