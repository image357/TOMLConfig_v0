project(tests)

add_executable(
        tests
        GlobalTest.cpp GlobalTest.h
)

target_link_libraries(
        tests
        PRIVATE
        GTest::gtest GTest::gmock GTest::gmock_main
)
