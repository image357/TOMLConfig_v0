//
// Created by koepke on 3/20/22.
//

#include "TOMLConfig/resource/filesystem/RootFileResource.h"

namespace config::resource {

RootFileResource::RootFileResource(const std::string& file_path)
        :RootResource(), m_file_resource(std::make_shared<FileResource>(file_path))
{
    add_resource(m_file_resource);
}

}
