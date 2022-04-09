cmake_minimum_required(VERSION 3.20)
include(../../cmake/utils/get_cmake_args.cmake)
project(external)

include(ExternalProject)
ExternalProject_Add(
        external
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        CMAKE_ARGS ${CMAKE_ARGS}
)
