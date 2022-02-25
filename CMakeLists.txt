cmake_minimum_required(VERSION 3.20)
project(TOMLConfig VERSION 1.0.0)

# dependencies
find_package(toml11 REQUIRED)

# main target
add_library(
        TOMLConfig
        STATIC
        src/IConfig.cpp src/IConfig.h
)

target_link_libraries(
        TOMLConfig
        PRIVATE
        toml11:toml11
)
