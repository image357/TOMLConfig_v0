cmake_minimum_required(VERSION 3.20)
project(TOMLConfig VERSION 1.0.0)

# dependencies
find_package(toml11 REQUIRED)
find_package(GTest REQUIRED)

# submodules
add_subdirectory(docs EXCLUDE_FROM_ALL)
add_subdirectory(tests EXCLUDE_FROM_ALL)

# main target
add_library(
        TOMLConfig
        STATIC
        src/IConfig.cpp include/TOMLConfig/IConfig.h
)

target_link_libraries(
        TOMLConfig
        PRIVATE
        toml11::toml11
)

target_include_directories(
        TOMLConfig
        PUBLIC
        include
)
