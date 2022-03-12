//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_NODERESOURCE_H
#define TOMLCONFIG_NODERESOURCE_H

#include <memory>
#include <unordered_map>
#include "TOMLConfig/resource/IResource.h"
#include "AbstractResourceException.h"

namespace config::resource {

class NodeResource : public IResource {
private:
    std::string name;
    IResource* parent = nullptr;
    std::unordered_map<std::string, std::shared_ptr<IResource>> children;

public:
    explicit NodeResource(const std::string& name);

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

    void add_resource(const std::shared_ptr<IResource>& resource);

private:
    void set_parent(IResource* resource) override;
};

}

#endif //TOMLCONFIG_NODERESOURCE_H
