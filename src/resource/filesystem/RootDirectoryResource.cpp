//
// Created by koepke on 3/19/22.
//

#include "TOMLConfig/resource/filesystem/RootDirectoryResource.h"

namespace config::resource {

RootDirectoryResource::RootDirectoryResource(const std::string& directory_path)
        :RootResource(), m_directory_resource(directory_path) { }

toml::value RootDirectoryResource::as_toml() const
{
    return m_directory_resource.as_toml();
}

}
