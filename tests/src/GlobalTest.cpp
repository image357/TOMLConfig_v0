//
// Created by koepke on 3/1/22.
//

#include "GlobalTest.h"
#include <iostream>
#include <toml.hpp>
#include <filesystem>

void GlobalTest::SetUp()
{
    Test::SetUp();
}

void GlobalTest::TearDown()
{
    Test::TearDown();
}

TEST_F(GlobalTest, succeed)
{
    SUCCEED();
}

TEST_F(GlobalTest, testVirtualDestructorChain)
{
    int i = 0;
    class First {
    public:
        First(int& ref)
                :ref(ref) { ++ref; }
        virtual ~First() { --ref; }
        int& ref;
    };
    {
        i = 0;
        std::unique_ptr<First> first = std::make_unique<First>(i);
        ASSERT_EQ(i, 1);
    }
    ASSERT_EQ(i, 0);

    class Second : public First {
    public:
        Second(int& ref)
                :First(ref) { ++ref; }
//        ~Second() { --ref; }
    };
    {
        i = 0;
        std::unique_ptr<First> second = std::make_unique<Second>(i);
        ASSERT_EQ(i, 2);
    }
    ASSERT_EQ(i, 1);

    class Third : public Second {
    public:
        Third(int& ref)
                :Second(ref) { ++ref; }
        ~Third() { --ref; }
    };
    {
        i = 0;
        std::unique_ptr<First> third = std::make_unique<Third>(i);
        ASSERT_EQ(i, 3);
    }
    ASSERT_EQ(i, 1);
}

TEST_F(GlobalTest, scanDirectory)
{
    std::filesystem::path path(RESOURCE_PATH "example01");
    std::filesystem::directory_iterator it(path);
    std::vector<std::string> entries;
    for (const auto& entry : it) {
        entries.emplace_back(entry.path().filename());
    }
    ASSERT_EQ(entries.size(), 3);
    ASSERT_NE(std::find(entries.begin(), entries.end(), ".gitkeep"), entries.end());
    ASSERT_NE(std::find(entries.begin(), entries.end(), "default"), entries.end());
    ASSERT_NE(std::find(entries.begin(), entries.end(), "overwrite"), entries.end());
}
