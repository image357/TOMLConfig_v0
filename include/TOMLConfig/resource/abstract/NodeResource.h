//
// Created by koepke on 3/6/22.
//

#ifndef TOMLCONFIG_NODERESOURCE_H
#define TOMLCONFIG_NODERESOURCE_H

#include <memory>
#include <vector>
#include "TOMLConfig/resource/IResource.h"

namespace config::resource {

class NodeResource : public IResource {
private:
    std::string name;
    std::shared_ptr<IResource> parent;
    std::vector<std::shared_ptr<IResource>> children;

public:
    NodeResource(const std::string& name, const std::shared_ptr<IResource>& parent);

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
};

}

#endif //TOMLCONFIG_NODERESOURCE_H
