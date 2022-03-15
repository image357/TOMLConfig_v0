//
// Created by koepke on 3/12/22.
//

#include "FilesystemResourceTreeTest.h"
#include <string>
#include "resource/utils/filesystem.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"
#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "TOMLConfig/resource/filesystem/DirectoryResource.h"

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
    ASSERT_EQ(toml_filepath_to_resource_name("/some/path/to/file.toml"), "file");
    ASSERT_THROW(toml_filepath_to_resource_name("/some/path/to/file.txt"), FilesystemResourceException);
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
    DirectoryResource resource(RESOURCE_PATH "example1");
}
