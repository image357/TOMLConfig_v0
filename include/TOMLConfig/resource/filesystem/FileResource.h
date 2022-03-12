//
// Created by koepke on 3/12/22.
//

#ifndef TOMLCONFIG_FILERESOURCE_H
#define TOMLCONFIG_FILERESOURCE_H

#include "TOMLConfig/resource/abstract/LeafResource.h"

namespace config::resource {

class FileResource : public LeafResource {
public:
    FileResource(const std::string& filepath);
};

}

#endif //TOMLCONFIG_FILERESOURCE_H
