cmake_minimum_required(VERSION 3.20)
include(../../cmake/get_cmake_args.cmake)
project(external_spdlog)

include(ExternalProject)
ExternalProject_Add(
        external
        GIT_REPOSITORY git@github.com:gabime/spdlog.git
        GIT_TAG v1.x
        CMAKE_ARGS ${CMAKE_ARGS}

        INSTALL_COMMAND
        "${CMAKE_COMMAND}"
        "--install"
        "${CMAKE_CURRENT_BINARY_DIR}/external-prefix/src/external-build"
        "--prefix"
        "${CMAKE_CURRENT_BINARY_DIR}/../install"
)
