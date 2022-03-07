//
// Created by koepke on 3/7/22.
//

#include "AbstractResourceTreeTest.h"
#include "TOMLConfig/resource/abstract/RootResource.h"
#include "TOMLConfig/resource/abstract/NodeResource.h"
#include "TOMLConfig/resource/abstract/LeafResource.h"

void AbstractResourceTreeTest::SetUp()
{
    mock_resource_ptr = std::make_shared<MockResource>();
    Test::SetUp();
}

void AbstractResourceTreeTest::TearDown()
{
    Test::TearDown();
}

TEST_F(AbstractResourceTreeTest, constructRoot)
{
    RootResource resource;
}

TEST_F(AbstractResourceTreeTest, constructNode)
{
    NodeResource resource("name", mock_resource_ptr);
}

TEST_F(AbstractResourceTreeTest, constructLeaf)
{
    LeafResource resource("name", mock_resource_ptr);
}
