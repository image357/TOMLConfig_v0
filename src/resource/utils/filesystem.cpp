//
// Created by koepke on 3/12/22.
//

#include "filesystem.h"
#include <filesystem>
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"

namespace config::resource {

std::string toml_filepath_to_resource_name(const std::string& filepath)
{
    std::filesystem::path path(filepath);
    if (path.extension()!=".toml") {
        throw FilesystemResourceException("File type has to be toml.");
    }
    auto filename = path.stem();
    return filename;
}

std::string directory_path_to_resource_name(const std::string& directory_path)
{
    std::filesystem::path path(directory_path);
    if (!std::filesystem::is_directory(path)) {
        throw FilesystemResourceException("Path must be a directory.");
    }
    std::string directory_name;
    if (path.has_filename()) {
        return path.filename();
    }
    if (path.has_parent_path()) {
        return path.parent_path().filename();
    }
    throw FilesystemResourceException("Invalid directory name.");
}

}
