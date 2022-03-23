//
// Created by koepke on 3/23/22.
//

#include "MergerTest.h"

void MergerTest::SetUp()
{
    Test::SetUp();

    default01["a"] = 1;
    overwrite01["a"] = 2;
    overwrite01["b"] = 2;
}

void MergerTest::TearDown()
{
    Test::TearDown();
}

TEST_F(MergerTest, construct)
{
    BasicMerger merger(default01, overwrite01);
}

TEST_F(MergerTest, merge01)
{
    BasicMerger merger(default01, overwrite01);
    merger.merge();
}
