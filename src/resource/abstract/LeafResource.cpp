//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/LeafResource.h"

namespace config::resource {

LeafResource::LeafResource(const std::string& name, const std::shared_ptr<IResource>& parent)
        :name(name), parent(parent) { }

std::string LeafResource::get_name() const
{
    return name;
}

std::string LeafResource::get_path() const
{
    return parent->get_path()+"/"+get_name();
}

ResourceType LeafResource::get_type() const
{
    return ResourceType::Leaf;
}

}
