//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/NodeResource.h"

namespace config::resource {

NodeResource::NodeResource(const std::string& name, const std::shared_ptr<IResource>& parent)
        :name(name), parent(parent) { }

std::string NodeResource::get_name() const
{
    return name;
}

std::string NodeResource::get_path() const
{
    return parent->get_path()+"/"+get_name();
}

ResourceType NodeResource::get_type() const
{
    return ResourceType::Node;
}

}
