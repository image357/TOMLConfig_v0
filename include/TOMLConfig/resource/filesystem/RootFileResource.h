//
// Created by koepke on 3/20/22.
//

#ifndef TOMLCONFIG_ROOTFILERESOURCE_H
#define TOMLCONFIG_ROOTFILERESOURCE_H

#include "TOMLConfig/resource/abstract/RootResource.h"
#include "FileResource.h"
#include <memory>

namespace config::resource {

class RootFileResource : public RootResource {
private:
    std::shared_ptr<FileResource> m_file_resource;

public:
    explicit RootFileResource(const std::string& file_path);
};

}

#endif //TOMLCONFIG_ROOTFILERESOURCE_H
