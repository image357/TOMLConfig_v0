//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_IRESOURCE_H
#define TOMLCONFIG_IRESOURCE_H

#include <string>
#include "ResourceType.h"

namespace config::resource {

class IResource {
public:
    virtual ~IResource() = default;

    virtual std::string get_name() const = 0;
    virtual std::string get_path() const = 0;
    virtual ResourceType get_type() const = 0;
};

}

#endif //TOMLCONFIG_IRESOURCE_H
