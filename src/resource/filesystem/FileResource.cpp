//
// Created by koepke on 3/12/22.
//

#include "TOMLConfig/resource/filesystem/FileResource.h"
#include "../utils/filesystem.h"

namespace config::resource {

FileResource::FileResource(const std::string& filepath)
        :LeafResource(toml_filepath_to_resource_name(filepath)) { }

}
