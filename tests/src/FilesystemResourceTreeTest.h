//
// Created by koepke on 3/12/22.
//

#ifndef TOMLCONFIG_FILESYSTEMRESOURCETREETEST_H
#define TOMLCONFIG_FILESYSTEMRESOURCETREETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "../mocks/MockResource.h"

using namespace config::resource;

class FilesystemResourceTreeTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    void assert_basic_toml(const toml::value& value);

    MockResource mock_resource;
    std::shared_ptr<MockResource> mock_resource_ptr;
};

#endif //TOMLCONFIG_FILESYSTEMRESOURCETREETEST_H
