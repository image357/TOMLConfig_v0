//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_TOML11TEST_H
#define TOMLCONFIG_TOML11TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class TOML11Test : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
};

#endif //TOMLCONFIG_TOML11TEST_H
