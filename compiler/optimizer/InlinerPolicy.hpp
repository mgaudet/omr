/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2017
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

#ifndef INLINER_POLICY_INCL
#define INLINER_POLICY_INCL

#include "optimizer/Inliner.hpp" 

namespace OMR
{

class InlinerPolicy : public TR::OptimizationPolicy, public OMR_InlinerHelper
   {
   public:
      InlinerPolicy(TR::Compilation *comp);
      virtual bool inlineRecognizedMethod(TR::RecognizedMethod method);
      int32_t getInitialBytecodeSize(TR::ResolvedMethodSymbol * methodSymbol, TR::Compilation *comp);
      virtual int32_t getInitialBytecodeSize(TR_ResolvedMethod *feMethod, TR::ResolvedMethodSymbol * methodSymbol, TR::Compilation *comp);
      virtual bool tryToInline(TR_CallTarget *, TR_CallStack *, bool);
      virtual bool inlineMethodEvenForColdBlocks(TR_ResolvedMethod *method);
      bool aggressiveSmallAppOpts() { return TR::Options::getCmdLineOptions()->getOption(TR_AggressiveOpts); }
      virtual bool willBeInlinedInCodeGen(TR::RecognizedMethod method);
      virtual bool canInlineMethodWhileInstrumenting(TR_ResolvedMethod *method);
      virtual bool skipHCRGuardForCallee(TR::ResolvedMethodSymbol *calleeSymbol){return false;}
      virtual bool dontPrivatizeArgumentsForRecognizedMethod(TR::RecognizedMethod recognizedMethod);
      virtual bool replaceSoftwareCheckWithHardwareCheck(TR_ResolvedMethod *calleeMethod);
      virtual bool tryToInlineTrivialMethod (TR_CallStack* callStack, TR_CallTarget* calltarget);
      virtual bool alwaysWorthInlining(TR_ResolvedMethod * calleeMethod, TR::Node *callNode);
      virtual void determineInliningHeuristic(TR::ResolvedMethodSymbol *callerSymbol);
      bool tryToInlineGeneral(TR_CallTarget *, TR_CallStack *, bool);
      virtual bool callMustBeInlined(TR_CallTarget *calltarget);
      bool mustBeInlinedEvenInDebug(TR_ResolvedMethod * calleeMethod, TR::TreeTop *callNodeTreeTop);
      virtual bool supressInliningRecognizedInitialCallee(TR_CallSite* callsite, TR::Compilation* comp);
      virtual TR_InlinerFailureReason checkIfTargetInlineable(TR_CallTarget* target, TR_CallSite* callsite, TR::Compilation* comp);
      virtual bool suitableForRemat(TR::Compilation *comp, TR::Node *node, TR_VirtualGuardSelection *guard);
   };

}
#endif
