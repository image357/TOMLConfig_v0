cmake_minimum_required(VERSION 3.20)
include(../../cmake/utils/get_cmake_args.cmake)
project(external_toml11)

include(ExternalProject)
ExternalProject_Add(
        external
        GIT_REPOSITORY git@github.com:ToruNiina/toml11.git
        GIT_TAG master
        CMAKE_ARGS ${CMAKE_ARGS}
)
