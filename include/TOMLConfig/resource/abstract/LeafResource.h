//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_LEAFRESOURCE_H
#define TOMLCONFIG_LEAFRESOURCE_H

#include <string>
#include <memory>
#include "TOMLConfig/resource/IResource.h"

namespace config::resource {

class LeafResource : public IResource {
private:
    std::string name;
    std::shared_ptr<IResource> parent;

public:
    LeafResource(const std::string& name, const std::shared_ptr<IResource>& parent);

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
};

}

#endif //TOMLCONFIG_LEAFRESOURCE_H
