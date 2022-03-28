//
// Created by koepke on 3/23/22.
//

#ifndef TOMLCONFIG_BASICMERGERTEST_H
#define TOMLCONFIG_BASICMERGERTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <toml.hpp>
#include "TOMLConfig/merge/BasicMerger.h"

namespace config::merge { }
using namespace config::merge;

class BasicMergerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
};

#endif //TOMLCONFIG_BASICMERGERTEST_H
