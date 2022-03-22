//
// Created by koepke on 3/19/22.
//

#include "TOMLConfig/resource/filesystem/RootDirectoryResource.h"
#include "TOMLConfig/resource/filesystem/FilesystemResourceException.h"

namespace config::resource {

RootDirectoryResource::RootDirectoryResource(const std::string& directory_path)
        :RootResource(), m_directory_resource(std::make_shared<DirectoryResource>(directory_path))
{
    add_resource(m_directory_resource);
}

}
