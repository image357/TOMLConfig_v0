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
    NodeResource resource("name");
}

TEST_F(AbstractResourceTreeTest, constructLeaf)
{
    LeafResource resource("name");
}

TEST_F(AbstractResourceTreeTest, makeSimpleTree)
{
    auto root_ptr = std::make_shared<RootResource>();

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node2");
    root_ptr->add_resource(node1_ptr);
    root_ptr->add_resource(node2_ptr);

    auto leaf11_ptr = std::make_shared<LeafResource>("leaf11");
    auto leaf12_ptr = std::make_shared<LeafResource>("leaf12");
    node1_ptr->add_resource(leaf11_ptr);
    node1_ptr->add_resource(leaf12_ptr);

    auto leaf21_ptr = std::make_shared<LeafResource>("leaf21");
    auto leaf22_ptr = std::make_shared<LeafResource>("leaf22");
    auto leaf23_ptr = std::make_shared<LeafResource>("leaf23");
    node2_ptr->add_resource(leaf21_ptr);
    node2_ptr->add_resource(leaf22_ptr);
    node2_ptr->add_resource(leaf23_ptr);
}

TEST_F(AbstractResourceTreeTest, throwOnSameNameInsert)
{
    auto root_ptr = std::make_shared<RootResource>();

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node1");
    root_ptr->add_resource(node1_ptr);
    ASSERT_THROW(root_ptr->add_resource(node2_ptr), AbstractResourceException);

    auto leaf1_ptr = std::make_shared<LeafResource>("leaf1");
    auto leaf2_ptr = std::make_shared<LeafResource>("leaf1");
    node1_ptr->add_resource(leaf1_ptr);
    ASSERT_THROW(node1_ptr->add_resource(leaf2_ptr), AbstractResourceException);
}
