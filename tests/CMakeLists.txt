project(tests)

add_executable(
        tests
        GlobalTest.cpp GlobalTest.h
        TOML11Test.cpp TOML11Test.h
        mocks/MockResource.h
        AbstractResourceTreeTest.cpp AbstractResourceTreeTest.h
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
