//
// Created by koepke on 3/20/22.
//

#include "TOMLConfig/resource/filesystem/RootFileResource.h"

namespace config::resource {

RootFileResource::RootFileResource(const std::string& filepath)
        :RootResource(), file_resource(filepath) { }

toml::value RootFileResource::as_toml() const
{
    return file_resource.as_toml();
}

}
