/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2017, 2017
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

#include "JitTest.hpp"
#include "jitbuilder_compiler.hpp"

#include <string>

class IllformedTrees : public TRTest::JitTest, public ::testing::WithParamInterface<std::string> {};

TEST_P(IllformedTrees, FailCompilation) {
    auto inputTrees = GetParam();
    auto trees = parseString(inputTrees.c_str());

    ASSERT_NOTNULL(trees);

    Tril::JitBuilderCompiler compiler{trees};

    ASSERT_DEATH(compiler.compile(), "VALIDATION ERROR")
            << "Compilation did not fail due to ill-formed input trees";
}

INSTANTIATE_TEST_CASE_P(TreeVerifierDeathTest, IllformedTrees, ::testing::Values(
    "(method return=Int32 (block (ireturn (iadd (iconst 1) (sconst 3)))))",
    "(method return=Int32 (block (ireturn (sadd (iconst 1) (iconst 3)))))",
    "(method return=Address (block (areturn (aiadd (aconst 4) (lconst 1)))))",
    "(method return=Address (block (areturn (aladd (aconst 4) (iconst 1)))))",
    "(method return=Address (block (areturn (aiadd (iconst 1) (aconst 4)))))",
    "(method return=Address (block (areturn (aladd (lconst 1) (aconst 4)))))",
    "(method return=Int32 (block (ireturn (acmpeq (iconst 4) (aconst 4)))))",
    "(method return=Int32 (block (ireturn (acmpge (lconst 4) (aconst 4)))))",
    "(method return=NoType (block (return (GlRegDeps))))",
    "(method return=Int32 (block (ireturn (GlRegDeps) (iconst 3))))",
    "(method return=Int32 (block (ireturn (GlRegDeps) (iadd (iconst 1) (iconst 3)))))",
    "(method return=Int32 (block (ireturn (iconst 3 (GlRegDeps)))))",
    "(method return=Int32 (block (ireturn (iadd (GlRegDeps) (iconst 1) (iconst 3)))))"
    ));

class WellformedTrees : public TRTest::JitTest, public ::testing::WithParamInterface<std::string> {};

TEST_P(WellformedTrees, CompileOnly) {
    auto inputTrees = GetParam();
    auto trees = parseString(inputTrees.c_str());

    ASSERT_NOTNULL(trees);

    Tril::JitBuilderCompiler compiler{trees};

    ASSERT_EQ(0, compiler.compile()) << "Compilation failed unexpectedly";
}

INSTANTIATE_TEST_CASE_P(TreeVerifierTest, WellformedTrees, ::testing::Values(
    "(method return=Int32 (block (ireturn (iconst 3))))",
    "(method return=Int32 (block (ireturn (sconst 3))))",
    "(method return=Int32 (block (ireturn (iadd (iconst 1) (iconst 3)))))",
    "(method return=Address (block (areturn (aladd (aconst 4) (lconst 1)))))",
    "(method return=Int32 (block (ireturn (acmpge (aconst 4) (aconst 4)))))",
    "(method return=Int32 (block (ireturn (scmpeq (sconst 1) (sconst 3)))))",
    "(method return=Int32 (block (ireturn (lcmpeq (lconst 1) (lconst 3)))))"
    ));
