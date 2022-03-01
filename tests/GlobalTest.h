//
// Created by koepke on 3/1/22.
//

#ifndef TOMLCONFIG_GLOBALTEST_H
#define TOMLCONFIG_GLOBALTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GlobalTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
};

#endif //TOMLCONFIG_GLOBALTEST_H
