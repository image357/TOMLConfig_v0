//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/RootResource.h"

namespace config::resource {

RootResource::RootResource() = default;

std::string RootResource::get_name() const
{
    return "";
}

std::string RootResource::get_path() const
{
    return "/";
}

ResourceType RootResource::get_type() const
{
    return ResourceType::Root;
}

void RootResource::add_resource(const std::shared_ptr<IResource>& resource)
{
    auto[it, flag] = children.try_emplace(resource->get_name(), resource);
    if (!flag) {
        throw AbstractResourceException("Cannot add resource");
    }
    resource->set_parent(this);
}

void RootResource::set_parent(IResource* resource)
{
    throw AbstractResourceException("Cannot set parent on RootResource");
}

toml::value RootResource::as_toml() const
{
    toml::table value;
    for (const auto& it : children) {
        value[it.second->get_name()] = it.second->as_toml();
    }
    return value;
}

}
