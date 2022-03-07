//
// Created by koepke on 3/7/22.
//

#ifndef TOMLCONFIG_ABSTRACTRESOURCETREETEST_H
#define TOMLCONFIG_ABSTRACTRESOURCETREETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "mocks/MockResource.h"

using namespace config::resource;

class AbstractResourceTreeTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    MockResource mock_resource;
    std::shared_ptr<MockResource> mock_resource_ptr;
};

#endif //TOMLCONFIG_ABSTRACTRESOURCETREETEST_H
