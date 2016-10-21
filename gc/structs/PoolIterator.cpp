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
 *******************************************************************************/

/**
 * @file
 * @ingroup GC_Structs
 */

#include "omrcfg.h"
#include "omrcomp.h"

#include "PoolIterator.hpp"

/**
 * Return the next slot in the pool.
 */
void** GC_PoolIterator::nextSlot()
{
    void** value = _nextValue;
    if (value) {
        _nextValue = (void**)pool_nextDo(&_state);
    }
    return value;
}
