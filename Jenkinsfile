// Jenkinsfile for Eclipse OMR. 
// 
// Requires a Jenkins install with at least two nodes, labelled 
// as follows: 
// - ppcle build test 
// - x86   build test 
//
// The intention is that this file be included in another that gets the 
// sources and stashes them into a stash called 'sources' 
//
// For example: 
//     
//     
//     node {
//         
//         stage('Get Sources') { 
//           deleteDir()
//           // Get some code from a GitHub repository
//           checkout([$class: 'GitSCM', 
//             branches: [[name: "*/${env.REPO_BRANCH}"]],  // So build can be parameterized. 
//             doGenerateSubmoduleConfigurations: false,
//             extensions: [],
//             submoduleCfg: [],
//             userRemoteConfigs: [[url: env.REPO_URL ]]])
//           
//           stash includes: '**', name: 'sources'
//         }
//         load 'Jenkinsfile'
//     }



stage('Build') 

parallel(
   "ppcle-64_cmprssptrs" : { 
      node('build && ppcle') {
         deleteDir()
         unstash 'sources' 
         sh 'make -f run_configure.mk OMRGLUE=./example/glue SPEC=linux_ppc-64_cmprssptrs_le_gcc'
         sh 'make'
      }
   },
   "390-64" : { 
      node('build && s390x') {
         deleteDir()
         unstash 'sources' 
         sh 'make -f run_configure.mk OMRGLUE=./example/glue SPEC=linux_390-64'
         sh 'make'
      }
   },
   "x86-64" : { 
      node('build && x86') {
         deleteDir()
         unstash 'sources' 
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
   "linux_390-64" : { 
      node('test && s390x') { 
         env.GTEST_FILTER = '-*dump_test_create_dump_*'
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
