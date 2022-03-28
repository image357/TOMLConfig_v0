//
// Created by koepke on 3/23/22.
//

#include "BasicMergerTest.h"

void BasicMergerTest::SetUp()
{
    Test::SetUp();
}

void BasicMergerTest::TearDown()
{
    Test::TearDown();
}

TEST_F(BasicMergerTest, construct)
{
    toml::value default_toml;
    toml::value overwrite_toml;
    BasicMerger merger(default_toml, overwrite_toml);
}

TEST_F(BasicMergerTest, mergeExample03File01)
{
    auto default_toml = toml::parse(RESOURCE_PATH "example03/default/file01.toml");
    auto overwrite_toml = toml::parse(RESOURCE_PATH "example03/overwrite/file01.toml");
    auto expected_toml = toml::parse(RESOURCE_PATH "example03/expected_BasicMerger/file01.toml");
    BasicMerger merger(default_toml, overwrite_toml);
    auto merged_toml = merger.merge();
    ASSERT_EQ(merged_toml, expected_toml);
}
