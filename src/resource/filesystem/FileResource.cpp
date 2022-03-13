//
// Created by koepke on 3/12/22.
//

#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "../utils/filesystem.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"

namespace config::resource {

FileResource::FileResource(const std::string& filepath)
        :LeafResource(toml_filepath_to_resource_name(filepath)), m_filepath(filepath)
{
    if (!std::filesystem::exists(m_filepath)) {
        throw FilesystemResourceException(m_filepath.string()+" does not exist.");
    }
    if (m_filepath.extension()!=".toml") {
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
    m_toml_content = toml::parse(m_filepath);
}

}
