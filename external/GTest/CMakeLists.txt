cmake_minimum_required(VERSION 3.20)
include(../../cmake/get_cmake_args.cmake)
project(external_GTest)

include(ExternalProject)
ExternalProject_Add(
        external
        GIT_REPOSITORY git@github.com:google/googletest.git
        GIT_TAG main
        CMAKE_ARGS ${CMAKE_ARGS}

        INSTALL_COMMAND
        "${CMAKE_COMMAND}"
        "--install"
        "${CMAKE_CURRENT_BINARY_DIR}/external-prefix/src/external-build"
        "--prefix"
        "${CMAKE_CURRENT_BINARY_DIR}/../install"
)
