//
// Created by koepke on 3/12/22.
//

#include "FilesystemResourceTreeTest.h"
#include <string>
#include "resource/utils/filesystem.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"
#include "TOMLConfig/resource/filesystem/FileResource.h"

void FilesystemResourceTreeTest::SetUp()
{
    Test::SetUp();
}

void FilesystemResourceTreeTest::TearDown()
{
    Test::TearDown();
}

TEST_F(FilesystemResourceTreeTest, convertFilepathToName)
{
    ASSERT_EQ(toml_filepath_to_resource_name("/some/path/to/file.toml"), "file");
    ASSERT_THROW(toml_filepath_to_resource_name("/some/path/to/file.txt"), FilesystemResourceException);
}

TEST_F(FilesystemResourceTreeTest, constructFileResource)
{
    FileResource resource("/some/path/to/file.toml");
    ASSERT_THROW(FileResource resource("/some/path/to/file.txt");, FilesystemResourceException);
}
