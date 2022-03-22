//
// Created by koepke on 3/19/22.
//

#ifndef TOMLCONFIG_ROOTDIRECTORYRESOURCE_H
#define TOMLCONFIG_ROOTDIRECTORYRESOURCE_H

#include "TOMLConfig/resource/abstract/RootResource.h"
#include "DirectoryResource.h"
#include <memory>

namespace config::resource {

class RootDirectoryResource : public RootResource {
private:
    std::shared_ptr<DirectoryResource> m_directory_resource;

public:
    explicit RootDirectoryResource(const std::string& directory_path);
};

}

#endif //TOMLCONFIG_ROOTDIRECTORYRESOURCE_H
