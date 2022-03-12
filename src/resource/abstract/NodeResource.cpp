//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/NodeResource.h"

namespace config::resource {

NodeResource::NodeResource(const std::string& name)
        :name(name) { }

std::string NodeResource::get_name() const
{
    return name;
}

std::string NodeResource::get_path() const
{
    return parent->get_path()+get_name()+"/";
}

ResourceType NodeResource::get_type() const
{
    return ResourceType::Node;
}

void NodeResource::add_resource(const std::shared_ptr<IResource>& resource)
{
    auto[it, flag] = children.try_emplace(resource->get_name(), resource);
    if (!flag) {
        throw AbstractResourceException("Cannot add resource");
    }
    resource->set_parent(this);
}

void NodeResource::set_parent(IResource* resource)
{
    parent = resource;
}

toml::value NodeResource::as_toml() const
{
    toml::value value;
    for (const auto& it : children) {
        value[it.second->get_name()] = it.second->as_toml();
    }
    return value;
}

}
