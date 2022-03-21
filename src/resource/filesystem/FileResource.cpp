//
// Created by koepke on 3/12/22.
//

#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "../utils/filesystem.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"

namespace config::resource {

FileResource::FileResource(const std::string& file_path)
        :LeafResource(toml_file_path_to_resource_name(file_path)), m_file_path(file_path)
{
    if (!std::filesystem::exists(m_file_path)) {
        throw FilesystemResourceException(m_file_path.string()+" does not exist.");
    }
    if (m_file_path.extension()!=".toml") {
        throw FilesystemResourceException("File type has to be toml.");
    }
    parse_file();
}

toml::value FileResource::as_toml() const
{
    return m_toml_content;
}

void FileResource::parse_file()
{
    m_toml_content = toml::parse(m_file_path);
}

}
