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

#ifndef TEST_TESTS_OMRTESTENV_HPP_
#define TEST_TESTS_OMRTESTENV_HPP_

#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include "compile/Method.hpp"
#include "gtest/gtest.h"

namespace TestCompiler {

class OMRTestEnv : public testing::Environment
   {
   public:
   virtual void SetUp();
   virtual void TearDown();
   static void initialize(char *options);
   static void shutdown();
};

}

#endif /* TEST_TESTS_OMRTESTENV_HPP_ */
