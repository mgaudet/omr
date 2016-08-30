/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2001, 2015
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
 *    Multiple authors (IBM Corp.) - initial API and implementation and/or
 *initial documentation
 *******************************************************************************/

/*
 * ===========================================================================
 * Module Information:
 *
 * DESCRIPTION:
 * Replace the system header file "ipc.h" so that we can redefine
 * the i/o functions that take/produce character strings
 * with our own ATOE functions.
 *
 * The compiler will find this header file in preference to the system one.
 * ===========================================================================
 */

#if __TARGET_LIB__ == 0X22080000 /*ibm@28725*/
#include <  //'PP.ADLE370.OS39028.SCEEH.SYS.H(ipc)'>                 /*ibm@28725*/
#else       /*ibm@28725*/
#include "prefixpath.h"
#include PREFIXPATH(sys / ipc.h) /*ibm@28725*/
#endif                           /*ibm@28725*/

#if defined(IBM_ATOE)
#if !defined(IBM_ATOE_SYS_FTOK)
#define IBM_ATOE_SYS_FTOK

#ifdef __cplusplus
extern "C" {
#endif

int atoe_ftok(const char *, int);

#ifdef __cplusplus
}
#endif

#undef ftok
#define ftok atoe_ftok

#endif
#endif

/* END OF FILE */
