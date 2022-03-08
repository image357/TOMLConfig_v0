//
// Created by koepke on 3/8/22.
//

#ifndef TOMLCONFIG_ABSTRACTRESOURCEEXCEPTION_H
#define TOMLCONFIG_ABSTRACTRESOURCEEXCEPTION_H

#include <stdexcept>

class AbstractResourceException : public std::runtime_error {
public:
    explicit AbstractResourceException(const std::string& what = "")
            :std::runtime_error(what) { }
};

#endif //TOMLCONFIG_ABSTRACTRESOURCEEXCEPTION_H
