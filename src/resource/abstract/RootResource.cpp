//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/RootResource.h"

namespace config::resource {

RootResource::RootResource() { }

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

}