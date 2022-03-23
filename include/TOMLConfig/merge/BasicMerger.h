//
// Created by koepke on 3/23/22.
//

#ifndef TOMLCONFIG_BASICMERGER_H
#define TOMLCONFIG_BASICMERGER_H

#include <string>
#include "IMerger.h"

namespace config::merge {

class BasicMerger : public IMerger {
    toml::value m_default_toml;
    toml::value m_overwrite_toml;

public:
    BasicMerger(const toml::value& default_toml, const toml::value& overwrite_toml);

    toml::value merge() const override;

private:
    void merge_table(toml::value& default_toml, const toml::value& overwrite_toml) const;
    void merge_array(toml::value& default_toml, const toml::value& overwrite_toml) const;
    void merge_value(toml::value& default_toml, const toml::value& overwrite_toml) const;
};

}

#endif //TOMLCONFIG_BASICMERGER_H
