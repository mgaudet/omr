/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2015
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
 *    Multiple authors (IBM Corp.) - initial API and implementation and/or initial documentation
 *******************************************************************************/

#define _GNU_SOURCE

#include <sys/ucontext.h>
#include <unistd.h>

#include "omrport.h"
#include "omrsignal_context.h"

void fillInUnixSignalInfo(struct OMRPortLibrary* portLibrary, void* contextInfo, struct J9UnixSignalInfo* j9Info)
{
    j9Info->platformSignalInfo.context = (ucontext_t*)contextInfo;
    /* module info is filled on demand */
}

uint32_t infoForSignal(
    struct OMRPortLibrary* portLibrary, struct J9UnixSignalInfo* info, int32_t index, const char** name, void** value)
{
    *name = "";

    switch (index) {

    case OMRPORT_SIG_SIGNAL_TYPE:
    case 0:
        *name = "J9Generic_Signal_Number";
        *value = &info->portLibrarySignalType;
        return OMRPORT_SIG_VALUE_32;

    case OMRPORT_SIG_SIGNAL_PLATFORM_SIGNAL_TYPE:
    case 1:
        *name = "Signal_Number";
        *value = &info->sigInfo->si_signo;
        return OMRPORT_SIG_VALUE_32;

    case OMRPORT_SIG_SIGNAL_ERROR_VALUE:
    case 2:
        *name = "Error_Value";
        *value = &info->sigInfo->si_errno;
        return OMRPORT_SIG_VALUE_32;

    case OMRPORT_SIG_SIGNAL_CODE:
    case 3:
        *name = "Signal_Code";
        *value = &info->sigInfo->si_code;
        return OMRPORT_SIG_VALUE_32;

    case OMRPORT_SIG_SIGNAL_HANDLER:
    case 4:
        *name = "Handler1";
        *value = &info->handlerAddress;
        return OMRPORT_SIG_VALUE_ADDRESS;

    case 5:
        *name = "Handler2";
        *value = &info->handlerAddress2;
        return OMRPORT_SIG_VALUE_ADDRESS;

    case OMRPORT_SIG_SIGNAL_INACCESSIBLE_ADDRESS:
    case 6:
        /* si_code > 0 indicates that the signal was generated by the kernel */
        if (info->sigInfo->si_code > 0) {
            if ((info->sigInfo->si_signo == SIGBUS) || (info->sigInfo->si_signo == SIGSEGV)) {
                *name = "InaccessibleAddress";
                *value = &info->sigInfo->si_addr;
                return OMRPORT_SIG_VALUE_ADDRESS;
            }
        }
        return OMRPORT_SIG_VALUE_UNDEFINED;

    default:
        return OMRPORT_SIG_VALUE_UNDEFINED;
    }
}

uint32_t infoForFPR(
    struct OMRPortLibrary* portLibrary, struct J9UnixSignalInfo* info, int32_t index, const char** name, void** value)
{
    switch (index) {
    default:
        return OMRPORT_SIG_VALUE_UNDEFINED;
    }
}

uint32_t infoForGPR(
    struct OMRPortLibrary* portLibrary, struct J9UnixSignalInfo* info, int32_t index, const char** name, void** value)
{
    struct sigcontext* const context = (struct sigcontext*)&info->platformSignalInfo.context->uc_mcontext;
    *name = "";

    switch (index) {
    case OMRPORT_SIG_GPR_ARM_R0:
    case 0:
        *name = "R0";
        *value = &context->arm_r0;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R1:
    case 1:
        *name = "R1";
        *value = &context->arm_r1;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R2:
    case 2:
        *name = "R2";
        *value = &context->arm_r2;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R3:
    case 3:
        *name = "R3";
        *value = &context->arm_r3;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R4:
    case 4:
        *name = "R4";
        *value = &context->arm_r4;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R5:
    case 5:
        *name = "R5";
        *value = &context->arm_r5;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R6:
    case 6:
        *name = "R6";
        *value = &context->arm_r6;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R7:
    case 7:
        *name = "R7";
        *value = &context->arm_r7;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R8:
    case 8:
        *name = "R8";
        *value = &context->arm_r8;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R9:
    case 9:
        *name = "R9";
        *value = &context->arm_r9;
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_ARM_R10:
    case 10:
        *name = "R10";
        *value = &context->arm_r10;
        return OMRPORT_SIG_VALUE_ADDRESS;
    default:
        return OMRPORT_SIG_VALUE_UNDEFINED;
    }
}

uint32_t infoForControl(
    struct OMRPortLibrary* portLibrary, struct J9UnixSignalInfo* info, int32_t index, const char** name, void** value)
{
    struct sigcontext* const context = (struct sigcontext*)&info->platformSignalInfo.context->uc_mcontext;
    *name = "";

    switch (index) {
    case OMRPORT_SIG_CONTROL_PC:
    case 0:
        *name = "FP"; /* R11 */
        *value = (void*)&(context->arm_fp);
        return OMRPORT_SIG_VALUE_ADDRESS;
    case 1:
        *name = "IP"; /* R12 */
        *value = (void*)&(context->arm_ip);
        return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_CONTROL_SP:
    case 2:
        *name = "SP"; /* R13 */
        *value = (void*)&(context->arm_sp);
        return OMRPORT_SIG_VALUE_ADDRESS;
    case 3:
        *name = "LR"; /* R14 */
        *value = (void*)&(context->arm_lr);
        return OMRPORT_SIG_VALUE_ADDRESS;
    case 4:
        *name = "PC"; /* R15 */
        *value = (void*)&(context->arm_pc);
        return OMRPORT_SIG_VALUE_ADDRESS;
    case 5:
        *name = "CPSR";
        *value = (void*)&(context->arm_cpsr);
        return OMRPORT_SIG_VALUE_ADDRESS;
    default:
        return OMRPORT_SIG_VALUE_UNDEFINED;
    }
}

uint32_t infoForModule(
    struct OMRPortLibrary* portLibrary, struct J9UnixSignalInfo* info, int32_t index, const char** name, void** value)
{
    void* address;
    Dl_info* dl_info = &(info->platformSignalInfo.dl_info);
    struct sigcontext* context = (struct sigcontext*)&info->platformSignalInfo.context->uc_mcontext;
    *name = "";

    address = (void*)context->arm_pc;
    int dl_result = dladdr(address, dl_info);

    switch (index) {
    case OMRPORT_SIG_MODULE_NAME:
    case 0:
        *name = "Module";
        if (dl_result) {
            *value = (void*)(dl_info->dli_fname);
            return OMRPORT_SIG_VALUE_STRING;
        }
        return OMRPORT_SIG_VALUE_UNDEFINED;
    case 1:
        *name = "Module_base_address";
        if (dl_result) {
            *value = (void*)&(dl_info->dli_fbase);
            return OMRPORT_SIG_VALUE_ADDRESS;
        }
        return OMRPORT_SIG_VALUE_UNDEFINED;
    case 2:
        *name = "Symbol";
        if (dl_result) {
            if (dl_info->dli_sname != NULL) {
                *value = (void*)(dl_info->dli_sname);
                return OMRPORT_SIG_VALUE_STRING;
            }
        }
        return OMRPORT_SIG_VALUE_UNDEFINED;
    case 3:
        *name = "Symbol_address";
        if (dl_result) {
            *value = (void*)&(dl_info->dli_saddr);
            return OMRPORT_SIG_VALUE_ADDRESS;
        }
        return OMRPORT_SIG_VALUE_UNDEFINED;
    default:
        return OMRPORT_SIG_VALUE_UNDEFINED;
    }
}
