//
// Created by koepke on 3/12/22.
//

#ifndef TOMLCONFIG_FILESYSTEMRESOURCEEXCEPTION_H
#define TOMLCONFIG_FILESYSTEMRESOURCEEXCEPTION_H

#include <stdexcept>

class FilesystemResourceException : public std::runtime_error {
public:
    explicit FilesystemResourceException(const std::string& what = "")
            :std::runtime_error(what) { }
};

#endif //TOMLCONFIG_FILESYSTEMRESOURCEEXCEPTION_H
