##############################################################################
#
# (c) Copyright IBM Corp. 2017
#
#  This program and the accompanying materials are made available
#  under the terms of the Eclipse Public License v1.0 and
#  Apache License v2.0 which accompanies this distribution.
#
#      The Eclipse Public License is available at
#      http://www.eclipse.org/legal/epl-v10.html
#
#      The Apache License v2.0 is available at
#      http://www.opensource.org/licenses/apache2.0.php
#
# Contributors:
#    Multiple authors (IBM Corp.) - initial implementation and documentation
###############################################################################

set(OMR_OS_DEFINITIONS 
   -DLINUX
   -D_FILE_OFFSET_BITS=64
)

set(OMR_OS_COMPILE_OPTIONS
   -pthread
)

# Setup things that can't be done on a per-target basis. 
macro(omr_os_global_configuration) 
   message(STATUS "Executing Linux global configuration") 
endmacro()

# Setup Linux things on a per-target basis. 
macro(omr_os_target_configuration target) 
endmacro()
