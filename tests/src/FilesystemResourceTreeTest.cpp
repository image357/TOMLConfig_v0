//
// Created by koepke on 3/12/22.
//

#include "FilesystemResourceTreeTest.h"
#include <string>
#include "resource/utils/filesystem.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"
#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "TOMLConfig/resource/filesystem/DirectoryResource.h"
#include "TOMLConfig/resource/filesystem/RootDirectoryResource.h"
#include "TOMLConfig/resource/filesystem/RootFileResource.h"

void FilesystemResourceTreeTest::SetUp()
{
    Test::SetUp();
}

void FilesystemResourceTreeTest::TearDown()
{
    Test::TearDown();
}

void FilesystemResourceTreeTest::assert_basic_toml(const toml::value& value) const
{
    ASSERT_EQ(toml::find<int>(value, "a"), 1);
    ASSERT_EQ(toml::find<double>(value, "b"), 2.0);
    ASSERT_EQ(toml::find<std::string>(value, "c"), "c");

    auto table1 = toml::find(value, "table1");
    ASSERT_EQ(toml::find<int>(table1, "a"), 3);
    ASSERT_EQ(toml::find<double>(table1, "b"), 4.0);
    ASSERT_EQ(toml::find<std::string>(table1, "c"), "c");

    auto table2 = toml::find(value, "table2");
    ASSERT_EQ(toml::find<int>(table2, "a"), 5);
    ASSERT_EQ(toml::find<double>(table2, "b"), 6.0);
    ASSERT_EQ(toml::find<std::string>(table2, "c"), "cc");

    auto subtable1 = toml::find(table2, "subtable1");
    ASSERT_EQ(toml::find<int>(subtable1, "d"), 7);
    ASSERT_EQ(toml::find<double>(subtable1, "e"), 8.0);
    ASSERT_EQ(toml::find<std::string>(subtable1, "f"), "ccc");
}

TEST_F(FilesystemResourceTreeTest, convertFilepathToName)
{
    ASSERT_EQ(toml_file_path_to_resource_name("/some/path/to/file.toml"), "file");
    ASSERT_THROW(toml_file_path_to_resource_name("/some/path/to/file.txt"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, constructFileResource)
{
    FileResource resource1(RESOURCE_PATH "basic.toml");
    ASSERT_THROW(FileResource resource2("/some/path/to/file.toml"), FilesystemResourceException);
    ASSERT_THROW(FileResource resource3(RESOURCE_PATH "basic.txt"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, convertFileResourceToToml)
{
    FileResource resource(RESOURCE_PATH "basic.toml");
    toml::value value = resource.as_toml();
    assert_basic_toml(value);
}

TEST_F(FilesystemResourceTreeTest, constructDirectoryResource)
{
    DirectoryResource resource1(RESOURCE_PATH "example01");
    DirectoryResource resource2(RESOURCE_PATH "example01/");
    ASSERT_THROW(DirectoryResource resource3(RESOURCE_PATH "does_not_exist"), FilesystemResourceException);
    ASSERT_THROW(DirectoryResource resource4(RESOURCE_PATH "basic.txt"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, convertDirectoryResourceExample01ToToml)
{
    DirectoryResource resource(RESOURCE_PATH "example01");
    auto value = resource.as_toml();
    ASSERT_EQ(value.size(), 2);
    ASSERT_TRUE(value["default"].is_table());
    ASSERT_TRUE(value["overwrite"].is_table());
    ASSERT_EQ(value["default"].size(), 1);
    ASSERT_EQ(value["overwrite"].size(), 1);
    assert_basic_toml(value["default"]["basic"]);
    assert_basic_toml(value["overwrite"]["basic"]);
}

TEST_F(FilesystemResourceTreeTest, constructRootDirectoryResource)
{
    RootDirectoryResource resource1(RESOURCE_PATH "example01");
    RootDirectoryResource resource2(RESOURCE_PATH "example01/");
    ASSERT_THROW(RootDirectoryResource resource3(RESOURCE_PATH "does_not_exist"), FilesystemResourceException);
    ASSERT_THROW(RootDirectoryResource resource4(RESOURCE_PATH "basic.txt"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, convertRootDirectoryResourceExample01ToToml)
{
    RootDirectoryResource resource(RESOURCE_PATH "example01");
    auto value = resource.as_toml();
    ASSERT_EQ(value["example01"].size(), 2);
    ASSERT_TRUE(value["example01"]["default"].is_table());
    ASSERT_TRUE(value["example01"]["overwrite"].is_table());
    ASSERT_EQ(value["example01"]["default"].size(), 1);
    ASSERT_EQ(value["example01"]["overwrite"].size(), 1);
    assert_basic_toml(value["example01"]["default"]["basic"]);
    assert_basic_toml(value["example01"]["overwrite"]["basic"]);
}

TEST_F(FilesystemResourceTreeTest, throwOnRootDirectoryResourceSetParent)
{
    auto root1_ptr = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01");
    auto root2_ptr = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01");
    ASSERT_THROW(root1_ptr->add_resource(root2_ptr), AbstractResourceException);
}

TEST_F(FilesystemResourceTreeTest, constructRootFileResource)
{
    RootFileResource resource1(RESOURCE_PATH "basic.toml");
    RootFileResource resource2(RESOURCE_PATH "./basic.toml");
    ASSERT_THROW(RootFileResource resource3(RESOURCE_PATH "does_not_exist.toml"), FilesystemResourceException);
    ASSERT_THROW(RootFileResource resource4(RESOURCE_PATH "example01"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, convertRootFileResourceToToml)
{
    RootFileResource resource(RESOURCE_PATH "basic.toml");
    auto value = resource.as_toml();
    assert_basic_toml(value["basic"]);
}

TEST_F(FilesystemResourceTreeTest, throwOnRootFileResourceSetParent)
{
    auto root1_ptr = std::make_shared<RootFileResource>(RESOURCE_PATH "basic.toml");
    auto root2_ptr = std::make_shared<RootFileResource>(RESOURCE_PATH "basic.toml");
    ASSERT_THROW(root1_ptr->add_resource(root2_ptr), AbstractResourceException);
}

TEST_F(FilesystemResourceTreeTest, testNameHandling)
{
    auto rootd_ptr1 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01");
    auto rootd_ptr2 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01/");
    auto rootd_ptr3 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "./example01");
    auto rootd_ptr4 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "./example01/");
    ASSERT_EQ(rootd_ptr1->get_name(), "");
    ASSERT_EQ(rootd_ptr2->get_name(), "");
    ASSERT_EQ(rootd_ptr3->get_name(), "");
    ASSERT_EQ(rootd_ptr4->get_name(), "");

    auto rootf_ptr1 = std::make_shared<RootFileResource>(RESOURCE_PATH "basic.toml");
    auto rootf_ptr2 = std::make_shared<RootFileResource>(RESOURCE_PATH "./basic.toml");
    ASSERT_EQ(rootf_ptr1->get_name(), "");
    ASSERT_EQ(rootf_ptr2->get_name(), "");

    auto node_ptr1 = std::make_shared<DirectoryResource>(RESOURCE_PATH "example01");
    auto node_ptr2 = std::make_shared<DirectoryResource>(RESOURCE_PATH "example01/");
    auto node_ptr3 = std::make_shared<DirectoryResource>(RESOURCE_PATH "./example01");
    auto node_ptr4 = std::make_shared<DirectoryResource>(RESOURCE_PATH "./example01/");
    ASSERT_EQ(node_ptr1->get_name(), "example01");
    ASSERT_EQ(node_ptr2->get_name(), "example01");
    ASSERT_EQ(node_ptr3->get_name(), "example01");
    ASSERT_EQ(node_ptr4->get_name(), "example01");

    auto leaf_ptr1 = std::make_shared<FileResource>(RESOURCE_PATH "basic.toml");
    auto leaf_ptr2 = std::make_shared<FileResource>(RESOURCE_PATH "./basic.toml");
    ASSERT_EQ(leaf_ptr1->get_name(), "basic");
    ASSERT_EQ(leaf_ptr2->get_name(), "basic");
}

TEST_F(FilesystemResourceTreeTest, testPathHandling)
{
    auto rootd_ptr1 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01");
    auto rootd_ptr2 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01/");
    auto rootd_ptr3 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "./example01");
    auto rootd_ptr4 = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "./example01/");
    ASSERT_EQ(rootd_ptr1->get_path(), "/");
    ASSERT_EQ(rootd_ptr2->get_path(), "/");
    ASSERT_EQ(rootd_ptr3->get_path(), "/");
    ASSERT_EQ(rootd_ptr4->get_path(), "/");

    auto rootf_ptr1 = std::make_shared<RootFileResource>(RESOURCE_PATH "basic.toml");
    auto rootf_ptr2 = std::make_shared<RootFileResource>(RESOURCE_PATH "./basic.toml");
    ASSERT_EQ(rootf_ptr1->get_path(), "/");
    ASSERT_EQ(rootf_ptr2->get_path(), "/");

    auto node_ptr1 = std::make_shared<DirectoryResource>(RESOURCE_PATH "example02");
    rootd_ptr1->add_resource(node_ptr1);
    auto node_ptr2 = std::make_shared<DirectoryResource>(RESOURCE_PATH "example02/");
    rootd_ptr2->add_resource(node_ptr2);
    auto node_ptr3 = std::make_shared<DirectoryResource>(RESOURCE_PATH "./example02");
    rootf_ptr1->add_resource(node_ptr3);
    auto node_ptr4 = std::make_shared<DirectoryResource>(RESOURCE_PATH "./example02/");
    rootf_ptr2->add_resource(node_ptr4);
    ASSERT_EQ(node_ptr1->get_path(), "/example02/");
    ASSERT_EQ(node_ptr2->get_path(), "/example02/");
    ASSERT_EQ(node_ptr3->get_path(), "/example02/");
    ASSERT_EQ(node_ptr4->get_path(), "/example02/");

    auto leaf_ptr1 = std::make_shared<FileResource>(RESOURCE_PATH "basic.toml");
    node_ptr1->add_resource(leaf_ptr1);
    auto leaf_ptr2 = std::make_shared<FileResource>(RESOURCE_PATH "./basic.toml");
    node_ptr2->add_resource(leaf_ptr2);
    auto leaf_ptr3 = std::make_shared<FileResource>(RESOURCE_PATH "basic.toml");
    rootd_ptr3->add_resource(leaf_ptr3);
    auto leaf_ptr4 = std::make_shared<FileResource>(RESOURCE_PATH "./basic.toml");
    rootd_ptr4->add_resource(leaf_ptr4);
    ASSERT_EQ(leaf_ptr1->get_path(), "/example02/basic");
    ASSERT_EQ(leaf_ptr2->get_path(), "/example02/basic");
    ASSERT_EQ(leaf_ptr3->get_path(), "/basic");
    ASSERT_EQ(leaf_ptr4->get_path(), "/basic");
}

TEST_F(FilesystemResourceTreeTest, testTypeHandling)
{
    auto rootd_ptr = std::make_shared<RootDirectoryResource>(RESOURCE_PATH "example01");
    ASSERT_EQ(rootd_ptr->get_type(), ResourceType::Root);

    auto rootf_ptr = std::make_shared<RootFileResource>(RESOURCE_PATH "basic.toml");
    ASSERT_EQ(rootf_ptr->get_type(), ResourceType::Root);

    auto node_ptr = std::make_shared<DirectoryResource>(RESOURCE_PATH "example01");
    ASSERT_EQ(node_ptr->get_type(), ResourceType::Node);

    auto leaf_ptr = std::make_shared<FileResource>(RESOURCE_PATH "basic.toml");
    ASSERT_EQ(leaf_ptr->get_type(), ResourceType::Leaf);
}
