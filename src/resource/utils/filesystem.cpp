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
        throw FilesystemResourceException("Filetype has to be toml.");
    }
    auto filename = path.stem();
    return filename;
}

}
