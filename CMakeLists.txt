# Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
# Distributed under the MIT License
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is furnished
# to do so, subject to the following conditions:
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.


cmake_minimum_required(VERSION 2.6)
project(ImpalaJIT)

set(IMPALAJIT_MAJOR_VERSION 1)
set(IMPALAJIT_MINOR_VERSION 0)
set(IMPALAJIT_PATCH_VERSION 0)
set(IMPALAJIT_VERSION
        ${IMPALAJIT_MAJOR_VERSION}.${IMPALAJIT_MINOR_VERSION}.${IMPALAJIT_PATCH_VERSION})


option(SHARED_LIB "Compile the shared library" OFF)
option(STATIC_LIB "Compile the static library" ON)
option(TESTS "Enable Tests" OFF)


set(source_files compiler/frontend/parser.cc
                 compiler/frontend/scanner.cc
                 compiler/driver.cc
                 compiler/function_context.cc
                 compiler/include/nodes/node.h
                 impalajit.cc
                 compiler/include/nodes/expression_nodes.h
                 compiler/include/nodes/compare_nodes.h
                 compiler/include/nodes/conditional_nodes.h
                 compiler/include/nodes/boolean_nodes.h
                 compiler/include/nodes/assignment_nodes.h
                 compiler/semantic_analysis/semantic_analyzer.cc
                 compiler/code-gen/code_generator.cpp
                 compiler/code-gen/codegen_visitor.cpp
                 compiler/code-gen/pretty_printer.cpp
                 compiler/engine/engine.cpp
                 compiler/engine/std_math_lib.cpp)


find_package(LLVM 10.0 REQUIRED CONFIG)
LLVM_MAP_COMPONENTS_TO_LIBNAMES(LLVM_LIBS core orcjit native)
message(STATUS "LLVM: ${LLVM_VERSION}")


if(SHARED_LIB)
    add_library(impalajit SHARED ${source_files})
endif()

if(STATIC_LIB)
    add_library(impalajit STATIC ${source_files})
endif()


target_include_directories(impalajit PRIVATE include
                                             include/impalajit
                                             compiler/include
                                             compiler/include/nodes
                                             compiler/include/types
                                             compiler/frontend/include
                                             compiler/semantic_analysis/include
                                             compiler/code-gen/include
                                             compiler/engine)

target_compile_options(impalajit PRIVATE -std=c++14 -O3)
target_link_libraries(impalajit PUBLIC -rdynamic -lm ${math_library} ${LLVM_LIBS})
target_include_directories(impalajit PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(impalajit PRIVATE ${LLVM_DEFINITIONS})


if (TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

export(TARGETS impalajit NAMESPACE IMPALA:: FILE ImpalaJitTargets.cmake)

# install target
install(TARGETS impalajit
        DESTINATION lib)

install(FILES include/impalajit.hh
        DESTINATION include)

install(FILES include/impalajit.f90
        DESTINATION include)

install(FILES include/impalajit/types.hh
        DESTINATION include/impalajit)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ImpalaJitTargets.cmake
        DESTINATION lib/cmake)


# uninstall target
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)
add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)


# code generation target
add_custom_target(generate
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/generate.cmake
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
