//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/NodeResource.h"

namespace config::resource {

NodeResource::NodeResource(const std::string& name)
        :m_name(name) { }

std::string NodeResource::get_name() const
{
    return m_name;
}

std::string NodeResource::get_path() const
{
    return m_parent->get_path()+get_name()+"/";
}

ResourceType NodeResource::get_type() const
{
    return ResourceType::Node;
}

void NodeResource::add_resource(const std::shared_ptr<IResource>& resource)
{
    auto[it, flag] = m_children.try_emplace(resource->get_name(), resource);
    if (!flag) {
        throw AbstractResourceException("Cannot add resource.");
    }
    resource->set_parent(this);
}

void NodeResource::set_parent(IResource* resource)
{
    m_parent = resource;
}

toml::value NodeResource::as_toml() const
{
    toml::table value;
    for (const auto& it : m_children) {
        value[it.second->get_name()] = it.second->as_toml();
    }
    return value;
}

}
