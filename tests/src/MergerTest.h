//
// Created by koepke on 3/23/22.
//

#ifndef TOMLCONFIG_MERGERTEST_H
#define TOMLCONFIG_MERGERTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <toml.hpp>
#include "TOMLConfig/merge/BasicMerger.h"

namespace config::merge { }
using namespace config::merge;

class MergerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    toml::value default01;
    toml::value overwrite01;
};

#endif //TOMLCONFIG_MERGERTEST_H
