//
// Created by koepke on 3/12/22.
//

#ifndef TOMLCONFIG_FILERESOURCE_H
#define TOMLCONFIG_FILERESOURCE_H

#include <filesystem>
#include <toml.hpp>
#include "TOMLConfig/resource/abstract/LeafResource.h"

namespace config::resource {

class FileResource : public LeafResource {
private:
    std::filesystem::path m_filepath;
    toml::value m_toml_content;

public:
    explicit FileResource(const std::string& filepath);

    toml::value as_toml() const override;
    void parse_file();
};

}

#endif //TOMLCONFIG_FILERESOURCE_H
