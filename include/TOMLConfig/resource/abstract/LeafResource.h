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
    IResource* parent = nullptr;

public:
    explicit LeafResource(const std::string& name);

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

private:
    void set_parent(IResource* resource) override;
};

}

#endif //TOMLCONFIG_LEAFRESOURCE_H
