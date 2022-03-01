//
// Created by koepke on 3/1/22.
//

#include "GlobalTest.h"

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
