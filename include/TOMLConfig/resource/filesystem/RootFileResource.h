//
// Created by koepke on 3/20/22.
//

#ifndef TOMLCONFIG_ROOTFILERESOURCE_H
#define TOMLCONFIG_ROOTFILERESOURCE_H

#include "TOMLConfig/resource/abstract/RootResource.h"
#include "FileResource.h"

namespace config::resource {

class RootFileResource : public RootResource {
private:
    FileResource file_resource;

public:
    RootFileResource(const std::string& filepath);

    toml::value as_toml() const override;
};

}

#endif //TOMLCONFIG_ROOTFILERESOURCE_H
