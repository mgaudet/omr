/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2016
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

#include "omrsignal_context.h"
#include "omrport.h"

#include <unistd.h>

void
fillInUnixSignalInfo(struct OMRPortLibrary* portLibrary, void* contextInfo,
                     struct J9UnixSignalInfo* j9Info)
{
  j9Info->platformSignalInfo.context = (ucontext_t*)contextInfo;
  /* module info is filled on demand */
}

uint32_t
infoForSignal(struct OMRPortLibrary* portLibrary, J9UnixSignalInfo* info,
              int32_t index, const char** name, void** value)
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
      if (0 < info->sigInfo->si_code) {
        if ((SIGBUS == info->sigInfo->si_signo) ||
            (SIGSEGV == info->sigInfo->si_signo)) {
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

uint32_t
infoForFPR(struct OMRPortLibrary* portLibrary, J9UnixSignalInfo* info,
           int32_t index, const char** name, void** value)
{
  mcontext_t* context =
    (mcontext_t*)&info->platformSignalInfo.context->uc_mcontext;
  _STRUCT_X86_FLOAT_STATE64 floatState = (*context)->__fs;
  *name = "";

  switch (index) {
    case 0:
      *name = "XMM0";
      *value = &floatState.__fpu_xmm0;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 1:
      *name = "XMM1";
      *value = &floatState.__fpu_xmm1;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 2:
      *name = "XMM2";
      *value = &floatState.__fpu_xmm2;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 3:
      *name = "XMM3";
      *value = &floatState.__fpu_xmm3;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 4:
      *name = "XMM4";
      *value = &floatState.__fpu_xmm4;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 5:
      *name = "XMM5";
      *value = &floatState.__fpu_xmm5;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 6:
      *name = "XMM6";
      *value = &floatState.__fpu_xmm6;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 7:
      *name = "XMM7";
      *value = &floatState.__fpu_xmm7;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 8:
      *name = "XMM8";
      *value = &floatState.__fpu_xmm8;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 9:
      *name = "XMM9";
      *value = &floatState.__fpu_xmm9;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 10:
      *name = "XMM10";
      *value = &floatState.__fpu_xmm10;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 11:
      *name = "XMM11";
      *value = &floatState.__fpu_xmm11;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 12:
      *name = "XMM12";
      *value = &floatState.__fpu_xmm12;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 13:
      *name = "XMM13";
      *value = &floatState.__fpu_xmm13;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 14:
      *name = "XMM14";
      *value = &floatState.__fpu_xmm14;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    case 15:
      *name = "XMM15";
      *value = &floatState.__fpu_xmm15;
      return OMRPORT_SIG_VALUE_FLOAT_64;
    default:
      return OMRPORT_SIG_VALUE_UNDEFINED;
  }
}

uint32_t
infoForGPR(struct OMRPortLibrary* portLibrary, J9UnixSignalInfo* info,
           int32_t index, const char** name, void** value)
{
  mcontext_t* context =
    (mcontext_t*)&info->platformSignalInfo.context->uc_mcontext;
  _STRUCT_X86_THREAD_STATE64 threadState = (*context)->__ss;
  *name = "";

  switch (index) {
    case OMRPORT_SIG_GPR_AMD64_RDI:
    case 0:
      *name = "RDI";
      *value = &threadState.__rdi;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_RSI:
    case 1:
      *name = "RSI";
      *value = &threadState.__rsi;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_RAX:
    case 2:
      *name = "RAX";
      *value = &threadState.__rax;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_RBX:
    case 3:
      *name = "RBX";
      *value = &threadState.__rbx;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_RCX:
    case 4:
      *name = "RCX";
      *value = &threadState.__rcx;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_RDX:
    case 5:
      *name = "RDX";
      *value = &threadState.__rdx;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R8:
    case 6:
      *name = "R8";
      *value = &threadState.__r8;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R9:
    case 7:
      *name = "R9";
      *value = &threadState.__r9;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R10:
    case 8:
      *name = "R10";
      *value = &threadState.__r10;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R11:
    case 9:
      *name = "R11";
      *value = &threadState.__r11;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R12:
    case 10:
      *name = "R12";
      *value = &threadState.__r12;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R13:
    case 11:
      *name = "R13";
      *value = &threadState.__r13;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R14:
    case 12:
      *name = "R14";
      *value = &threadState.__r14;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case OMRPORT_SIG_GPR_AMD64_R15:
    case 13:
      *name = "R15";
      *value = &threadState.__r15;
      return OMRPORT_SIG_VALUE_ADDRESS;
    default:
      return OMRPORT_SIG_VALUE_UNDEFINED;
  }
}

uint32_t
infoForControl(struct OMRPortLibrary* portLibrary, J9UnixSignalInfo* info,
               int32_t index, const char** name, void** value)
{
  mcontext_t* context =
    (mcontext_t*)&info->platformSignalInfo.context->uc_mcontext;
  _STRUCT_X86_THREAD_STATE64 threadState = (*context)->__ss;
  _STRUCT_X86_EXCEPTION_STATE64 exceptionState = (*context)->__es;
  *name = "";

  switch (index) {
    case OMRPORT_SIG_CONTROL_PC:
    case 0:
      *name = "RIP";
      *value = (void*)&(threadState.__rip);
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 1:
      *name = "GS";
      *value = (void*)&(threadState.__gs);
      return OMRPORT_SIG_VALUE_16;
    case 2:
      *name = "FS";
      *value = (void*)&(threadState.__fs);
      return OMRPORT_SIG_VALUE_16;
    case OMRPORT_SIG_CONTROL_SP:
    case 3:
      *name = "RSP";
      *value = (void*)&(threadState.__rsp);
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 4:
      *name = "RFlags";
      *value = (void*)&(threadState.__rflags);
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 5:
      *name = "CS";
      *value = (void*)&(threadState.__cs);
      return OMRPORT_SIG_VALUE_16;
    case OMRPORT_SIG_CONTROL_BP:
    case 6:
      *name = "RBP";
      *value = &threadState.__rbp;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 7:
      *name = "ERR";
      *value = &exceptionState.__err;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 8:
      *name = "TRAPNO";
      *value = &exceptionState.__trapno;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 9:
      *name = "CPU";
      *value = &exceptionState.__cpu;
      return OMRPORT_SIG_VALUE_ADDRESS;
    case 10:
      *name = "FAULTVADDR";
      *value = &exceptionState.__faultvaddr;
      return OMRPORT_SIG_VALUE_ADDRESS;
    default:
      return OMRPORT_SIG_VALUE_UNDEFINED;
  }
}

uint32_t
infoForModule(struct OMRPortLibrary* portLibrary, J9UnixSignalInfo* info,
              int32_t index, const char** name, void** value)
{
  Dl_info* dl_info = &(info->platformSignalInfo.dl_info);
  mcontext_t* context =
    (mcontext_t*)&info->platformSignalInfo.context->uc_mcontext;
  _STRUCT_X86_THREAD_STATE64 threadState = (*context)->__ss;
  *name = "";

  int dl_result = dladdr((void*)threadState.__rip, dl_info);

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
