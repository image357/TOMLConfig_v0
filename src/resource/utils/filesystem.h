//
// Created by koepke on 3/12/22.
//

#ifndef TOMLCONFIG_FILESYSTEM_H
#define TOMLCONFIG_FILESYSTEM_H

#include <string>

namespace config::resource {

std::string toml_filepath_to_resource_name(const std::string& filepath);

}

#endif //TOMLCONFIG_FILESYSTEM_H
