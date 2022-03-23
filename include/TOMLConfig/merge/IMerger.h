//
// Created by koepke on 3/23/22.
//

#ifndef TOMLCONFIG_IMERGER_H
#define TOMLCONFIG_IMERGER_H

#include <toml.hpp>

namespace config::merge {

class IMerger {
public:
    virtual ~IMerger() = default;

    virtual toml::value merge() const = 0;
};

}

#endif //TOMLCONFIG_IMERGER_H
