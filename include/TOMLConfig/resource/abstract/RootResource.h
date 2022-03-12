//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_ROOTRESOURCE_H
#define TOMLCONFIG_ROOTRESOURCE_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "TOMLConfig/resource/IResource.h"
#include "AbstractResourceException.h"

namespace config::resource {

class RootResource : public IResource {
private:
    std::unordered_map<std::string, std::shared_ptr<IResource>> children;

public:
    RootResource();

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

    void add_resource(const std::shared_ptr<IResource>& resource);

private:
    void set_parent(IResource* resource) override;
};

}

#endif //TOMLCONFIG_ROOTRESOURCE_H
