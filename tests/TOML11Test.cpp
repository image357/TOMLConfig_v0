//
// Created by koepke on 3/6/22.
//

#include "TOML11Test.h"
#include <toml.hpp>

void TOML11Test::SetUp()
{
    Test::SetUp();
}

void TOML11Test::TearDown()
{
    Test::TearDown();
}

TEST_F(TOML11Test, injectTOMLValueTree) {
    auto basic = toml::parse(RESOURCE_PATH "./basic.toml");
    toml::value value;
    value["basic"] = basic;
    ASSERT_TRUE(value.contains("basic"));
    ASSERT_TRUE(value["basic"].contains("a"));
    ASSERT_TRUE(value["basic"].contains("b"));
    ASSERT_TRUE(value["basic"].contains("c"));
    ASSERT_TRUE(value["basic"].contains("table1"));
    ASSERT_TRUE(value["basic"].contains("table2"));
}
