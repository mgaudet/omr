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

#ifndef PPCOUTOFLINECODESECTION_INCL
#define PPCOUTOFLINECODESECTION_INCL

#include "codegen/InstOpCode.hpp" // for InstOpCode, etc
#include "codegen/OutOfLineCodeSection.hpp" // for TR_OutOfLineCodeSection
#include "codegen/RegisterConstants.hpp" // for TR_RegisterKinds
#include "il/ILOpCodes.hpp" // for ILOpCodes

namespace TR {
class CodeGenerator;
}
namespace TR {
class LabelSymbol;
}
namespace TR {
class Node;
}
namespace TR {
class Register;
}

class TR_PPCOutOfLineCodeSection : public TR_OutOfLineCodeSection {

public:
    TR_PPCOutOfLineCodeSection(TR::LabelSymbol* entryLabel, TR::LabelSymbol* restartLabel, TR::CodeGenerator* cg)
        : TR_OutOfLineCodeSection(entryLabel, restartLabel, cg)
    {
    }

    TR_PPCOutOfLineCodeSection(TR::LabelSymbol* entryLabel, TR::CodeGenerator* cg)
        : TR_OutOfLineCodeSection(entryLabel, cg)
    {
    }
    // For calls
    //
    TR_PPCOutOfLineCodeSection(TR::Node* callNode, TR::ILOpCodes callOp, TR::Register* targetReg,
        TR::LabelSymbol* entryLabel, TR::LabelSymbol* restartLabel, TR::CodeGenerator* cg);

    TR_PPCOutOfLineCodeSection(TR::Node* callNode, TR::ILOpCodes callOp, TR::Register* targetReg,
        TR::LabelSymbol* entryLabel, TR::LabelSymbol* restartLabel, TR::InstOpCode::Mnemonic targetRegMovOpcode,
        TR::CodeGenerator* cg);

public:
    void assignRegisters(TR_RegisterKinds kindsToBeAssigned);
    void generatePPCOutOfLineCodeSectionDispatch();
};
#endif
