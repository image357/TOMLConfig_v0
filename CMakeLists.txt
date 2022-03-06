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
        include/TOMLConfig/resource/IResource.h
        include/TOMLConfig/resource/ResourceType.h
        src/resource/abstract/RootResource.cpp include/TOMLConfig/resource/abstract/RootResource.h
        src/resource/abstract/NodeResource.cpp include/TOMLConfig/resource/abstract/NodeResource.h
        src/resource/abstract/LeafResource.cpp include/TOMLConfig/resource/abstract/LeafResource.h
)

target_link_libraries(
        TOMLConfig
        PUBLIC
        toml11::toml11
)

include(GNUInstallDirs)
target_include_directories(
        TOMLConfig
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}>
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src> # for tests
)
