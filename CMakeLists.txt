cmake_minimum_required(VERSION 3.20)
include(cmake/get_cmake_args.cmake)
project(TOMLConfig VERSION 1.0.0)

# dependencies
include(cmake/add_external_package.cmake)

add_external_package(toml11 CMAKE_ARGS ${CMAKE_ARGS})
find_package(toml11 REQUIRED)
add_external_package(spdlog CMAKE_ARGS ${CMAKE_ARGS})
find_package(spdlog REQUIRED)
add_external_package(GTest CMAKE_ARGS ${CMAKE_ARGS})
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
        include/TOMLConfig/resource/abstract/AbstractResourceException.h
        src/resource/utils/filesystem.cpp src/resource/utils/filesystem.h
        include/TOMLConfig/resource/filesystem/FilesystemResourceException.h
        src/resource/filesystem/FileResource.cpp include/TOMLConfig/resource/filesystem/FileResource.h
        src/resource/filesystem/DirectoryResource.cpp include/TOMLConfig/resource/filesystem/DirectoryResource.h
        src/resource/filesystem/RootDirectoryResource.cpp include/TOMLConfig/resource/filesystem/RootDirectoryResource.h
        src/resource/filesystem/RootFileResource.cpp include/TOMLConfig/resource/filesystem/RootFileResource.h
        include/TOMLConfig/merge/IMerger.h
        src/merge/BasicMerger.cpp include/TOMLConfig/merge/BasicMerger.h
)

target_link_libraries(
        TOMLConfig
        PUBLIC
        toml11::toml11
        spdlog::spdlog
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
