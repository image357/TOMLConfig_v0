//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_ROOTRESOURCE_H
#define TOMLCONFIG_ROOTRESOURCE_H

#include <memory>
#include <vector>
#include "TOMLConfig/resource/IResource.h"

namespace config::resource {

class RootResource : public IResource {
private:
    std::vector<std::shared_ptr<IResource>> children;

public:
    RootResource();

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
};

}

#endif //TOMLCONFIG_ROOTRESOURCE_H
