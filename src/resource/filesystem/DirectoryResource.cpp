//
// Created by koepke on 3/15/22.
//

#include "TOMLConfig/resource/filesystem/DirectoryResource.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"
#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "../utils/filesystem.h"
#include <filesystem>
#include <memory>

namespace config::resource {

DirectoryResource::DirectoryResource(const std::string& directory_path)
        :NodeResource(directory_path_to_resource_name(directory_path)), m_directory_path(directory_path)
{
    if (!std::filesystem::exists(m_directory_path)) {
        throw FilesystemResourceException(m_directory_path.string()+" does not exist.");
    }
    if (!std::filesystem::is_directory(m_directory_path)) {
        throw FilesystemResourceException("Path must be a directory.");
    }
    add_directory_resources();
}

void DirectoryResource::add_directory_resources()
{
    std::filesystem::directory_iterator it(m_directory_path);
    for (const auto& entry : it) {
        if (entry.is_directory()) {
            if (entry.path().filename().string()[0]=='.') continue;
            auto temp = std::make_shared<DirectoryResource>(entry.path().string());
            this->add_resource(temp);
            continue;
        }
        if (entry.is_regular_file()) {
            if (entry.path().filename().string()[0]=='.') continue;
            auto temp = std::make_shared<FileResource>(entry.path().string());
            this->add_resource(temp);
            continue;
        }
        throw FilesystemResourceException("Cannot deduce filesystem resource type.");
    }
}

}
