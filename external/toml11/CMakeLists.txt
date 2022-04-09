cmake_minimum_required(VERSION 3.20)
include(../../cmake/utils/get_cmake_args.cmake)
project(external)

include(ExternalProject)
ExternalProject_Add(
        external
        GIT_REPOSITORY https://github.com/ToruNiina/toml11.git
        GIT_TAG v3.7.1
        CMAKE_ARGS ${CMAKE_ARGS}
)
