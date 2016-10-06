// Jenkinsfile for Eclipse OMR. 
// 
// Requires a Jenkins install with at least two nodes, labelled 
// as follows: 
// - ppcle build test 
// - x86   build test 


stage('Build') 

parallel(
   "ppcle-64_cmprssptrs" : { 
      node('build && ppcle') {
         checkout scm
         sh 'git clean -f -d -x' // Make sure clean!
         sh 'make -f run_configure.mk OMRGLUE=./example/glue SPEC=linux_ppc-64_cmprssptrs_le_gcc'
         sh 'make'
      }
   },
   "x86-64" : { 
      node('build && x86') {
         checkout scm
         sh 'git clean -f -d -x' // Make sure clean!
         sh 'make -f run_configure.mk OMRGLUE=./example/glue SPEC=linux_x86-64'
         sh 'make'
      }
   })


stage('Test')
parallel(
   "ppcle-64_cmprssptrs" : { 
      node('test && ppcle') { 
         env.GTEST_FILTER = '-*dump_test_create_dump_*:*sysinfo_test_sysinfo*'
         sh 'make test'
      }
   }, 
   "x86-64" : { 
      node('test && x86') { 
         env.GTEST_FILTER = '-*dump_test_create_dump_*'
         sh 'ulimit -c unlimited'
         sh 'make test'
      }
   }) 
