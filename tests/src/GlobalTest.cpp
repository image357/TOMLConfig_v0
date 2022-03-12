//
// Created by koepke on 3/1/22.
//

#include "GlobalTest.h"
#include <iostream>
#include <toml.hpp>

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
