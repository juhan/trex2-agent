# -*- cmake -*-
########################################################################
# Copyright (c) 2011, Ricardo Martins                                  #
# All rights reserved.                                                 #
#                                                                      #
# Redistribution and use in source and binary forms, with or without   #
# modification, are permitted provided that the following conditions   #
# are met:                                                             #
#                                                                      #
# Redistributions of source code must retain the above copyright       #
# notice, this list of conditions and the following disclaimer.        #
# Redistributions in binary form must reproduce the above copyright    #
# notice, this list of conditions and the following disclaimer in the  #
# documentation and/or other materials provided with the distribution. #
#                                                                      #
# Neither the name of the Universidade do Porto - Faculdade de         #
# Engenharia nor the names of its contributors may be used to endorse  #
# or promote products derived from this software without specific      #
# prior written permission.                                            #
#                                                                      #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  #
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT    #
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS    #
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE       #
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, #
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, #
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;     #
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER     #
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   # 
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN    #
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE      #
# POSSIBILITY OF SUCH DAMAGE.                                          #
########################################################################

add_library(TREXutils SHARED
  Exception.cc
  ErrnoExcept.cc
  SingletonDummy.cc
  SingletonServer.cc
  TREXversion.cc
  TextLog.cc
  XmlUtils.cc
  LogManager.cc
  Pdlfcn.cc
  PluginLoader.cc
  RStat.cc
)

add_dependencies(core TREXutils)
target_link_libraries(TREXutils ${SYSTEM_LIBRARIES})
trex_lib(TREXutils)

set_property(SOURCE Pdlfcn.cc 
  PROPERTY COMPILE_DEFINITIONS SUFSHARE="${CMAKE_SHARED_LIBRARY_SUFFIX}")

install(DIRECTORY . DESTINATION include/trex/utils
  FILES_MATCHING PATTERN "*.hh" PATTERN "*.tcc"
  PATTERN "private" EXCLUDE
  PATTERN ".svn" EXCLUDE)

install(TARGETS TREXutils DESTINATION lib)