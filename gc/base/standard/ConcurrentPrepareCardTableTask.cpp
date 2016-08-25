/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 1991, 2015
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

#include "omrcfg.h"

#if defined(AIXPPC) || defined(LINUXPPC)

#if defined(OMR_GC_MODRON_CONCURRENT_MARK)

#include "ConcurrentCardTableForWC.hpp"

#include "ConcurrentPrepareCardTableTask.hpp"

void
MM_ConcurrentPrepareCardTableTask::run(MM_EnvironmentBase* envBase)
{
  MM_EnvironmentStandard* env = MM_EnvironmentStandard::getEnvironment(envBase);
  _cardTable->prepareCardTableChunk(env, _firstCard, _lastCard, _action);
}

#endif /* OMR_GC_MODRON_CONCURRENT_MARK */
#endif /* AIXPPC || LINUXPPC */
