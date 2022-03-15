//
// Created by koepke on 3/15/22.
//

#ifndef TOMLCONFIG_DIRECTORYRESOURCE_H
#define TOMLCONFIG_DIRECTORYRESOURCE_H

#include <filesystem>
#include "TOMLConfig/resource/abstract/NodeResource.h"

namespace config::resource {

class DirectoryResource : public NodeResource {
private:
    std::filesystem::path m_directory_path;

public:
    explicit DirectoryResource(const std::string& directory_path);

    void add_directory_resources();
};

}

#endif //TOMLCONFIG_DIRECTORYRESOURCE_H
