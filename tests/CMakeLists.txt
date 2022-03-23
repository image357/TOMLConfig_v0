project(tests)

add_executable(
        tests
        src/GlobalTest.cpp src/GlobalTest.h
        src/TOML11Test.cpp src/TOML11Test.h
        mocks/MockResource.h
        src/AbstractResourceTreeTest.cpp src/AbstractResourceTreeTest.h
        src/FilesystemResourceTreeTest.cpp src/FilesystemResourceTreeTest.h
        src/MergerTest.cpp src/MergerTest.h
)

target_link_libraries(
        tests
        PRIVATE
        GTest::gtest GTest::gmock GTest::gmock_main
        toml11::toml11
        TOMLConfig
)

target_compile_definitions(
        tests
        PRIVATE
        RESOURCE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/resources/\"
)

include(cmake/init_resources.cmake)
