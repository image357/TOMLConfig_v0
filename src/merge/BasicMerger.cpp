//
// Created by koepke on 3/23/22.
//

#include "TOMLConfig/merge/BasicMerger.h"

namespace config::merge {

BasicMerger::BasicMerger(const toml::value& default_toml, const toml::value& overwrite_toml)
        :m_default_toml(default_toml), m_overwrite_toml(overwrite_toml) { }

toml::value BasicMerger::merge() const
{
    toml::value result = m_default_toml;
    merge_table(result, m_overwrite_toml);
    return result;
}

void BasicMerger::merge_table(toml::value& default_toml, const toml::value& overwrite_toml) const
{
    if (!default_toml.is_table()) {
        default_toml = overwrite_toml;
        return;
    }

    for (const auto&[k, v] : overwrite_toml.as_table()) {
        if (!default_toml.contains(k)) {
            default_toml[k] = v;
            continue;
        }
        if (v.is_table()) {
            merge_table(default_toml[k], v);
            continue;
        }
        if (v.is_array()) {
            merge_array(default_toml[k], v);
            continue;
        }
        merge_value(default_toml[k], v);
    }
}

void BasicMerger::merge_array(toml::value& default_toml, const toml::value& overwrite_toml) const
{
    if (!default_toml.is_array()) {
        default_toml = overwrite_toml;
        return;
    }

    std::size_t position = 0;
    for (const auto& v : overwrite_toml.as_array()) {
        if (position>=default_toml.size()) {
            default_toml.emplace_back(v);
            ++position;
            continue;
        }
        if (v.is_table()) {
            merge_table(default_toml[position], v);
            ++position;
            continue;
        }
        if (v.is_array()) {
            merge_array(default_toml[position], v);
            ++position;
            continue;
        }
        merge_value(default_toml[position], v);
        ++position;
    }
}

void BasicMerger::merge_value(toml::value& default_toml, const toml::value& overwrite_toml) const
{
    default_toml = overwrite_toml;
}

}
