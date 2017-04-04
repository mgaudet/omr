/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2016, 2016
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


#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <dlfcn.h>
#include <errno.h>

#include "Jit.hpp"
#include "ilgen/TypeDictionary.hpp"
#include "ilgen/MethodBuilder.hpp"
#include "Lambda.hpp"

using std::cout;
using std::cerr;


int
main(int argc, char *argv[])
   {
   cout << "Step 1: initialize JIT\n";
   bool initialized = initializeJit();
   if (!initialized)
      {
      cerr << "FAIL: could not initialize JIT\n";
      exit(-1);
      }

   cout << "Step 2: define type dictionary\n";
   TR::TypeDictionary types;

   cout << "Step 3: compile method builder\n";

   LambdaBuilder method(&types, 
                        [](TR::MethodBuilder* b) -> bool { 
                           cout << "SimpleMethod::buildIL() running!\n";
                           b->Return(
                                  b->Add(
                                      b->Load("value"),
                                      b->ConstInt32(1)));

                           return true;
                        } 
                        );
   method.DefineLine(LINETOSTR(__LINE__));
   method.DefineFile(__FILE__);

   method.DefineName("increment");
   method.DefineParameter("value", types.toIlType<int32_t>());
   method.DefineReturnType(types.toIlType<int32_t>());


   uint8_t *entry = 0;
   int32_t rc = compileMethodBuilder(&method, &entry);
   if (rc != 0)
      {
      cerr << "FAIL: compilation error " << rc << "\n";
      exit(-2);
      }

   cout << "Step 4: invoke compiled code and print results\n";
   typedef int32_t (SimpleMethodFunction)(int32_t);
   SimpleMethodFunction *increment = (SimpleMethodFunction *) entry;

   int32_t v;
   v=0;   cout << "increment(" << v << ") == " << increment(v) << "\n";
   v=1;   cout << "increment(" << v << ") == " << increment(v) << "\n";
   v=10;  cout << "increment(" << v << ") == " << increment(v) << "\n";
   v=-15; cout << "increment(" << v << ") == " << increment(v) << "\n";

   cout << "Step 5: shutdown JIT\n";
   shutdownJit();
   }
