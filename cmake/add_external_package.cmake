include(CMakeParseArguments)

function(add_external_package)
    # argument parsing
    set(_add_external_package_opt EXACT FORCE)
    set(_add_external_package_sval VERSION)
    set(_add_external_package_mval CMAKE_ARGS)
    cmake_parse_arguments(
            _add_external_package_arg
            "${_add_external_package_opt}"
            "${_add_external_package_sval}"
            "${_add_external_package_mval}"
            ${ARGN}
    )

    list(LENGTH _add_external_package_arg_UNPARSED_ARGUMENTS _add_external_package_ualen)
    if (NOT ${_add_external_package_ualen} EQUAL 1)
        message(FATAL_ERROR "argument error in add_external_package")
    endif ()
    set(_add_external_package_arg_NAME "${_add_external_package_arg_UNPARSED_ARGUMENTS}")

    # check if package is already installed
    if (${_add_external_package_arg_EXACT})
        find_package(${_add_external_package_arg_NAME} ${_add_external_package_arg_VERSION} EXACT QUIET CONFIG)
    else ()
        find_package(${_add_external_package_arg_NAME} ${_add_external_package_arg_VERSION} QUIET CONFIG)
    endif ()

    if (NOT "${_add_external_package_arg_FORCE}" AND "${${_add_external_package_arg_NAME}_FOUND}")
        message(STATUS "Using global installation of ${_add_external_package_arg_NAME}")
        return()
    endif ()
    message(STATUS "Using local installation of ${_add_external_package_arg_NAME}")

    # check if install config is present
    IF (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/${_add_external_package_arg_NAME}/CMakeLists.txt")
        message(FATAL_ERROR "Cannot find ${CMAKE_CURRENT_SOURCE_DIR}/external/${_add_external_package_arg_NAME}/CMakeLists.txt")
    endif ()

    # Configure, build and install the external project
    IF (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/_external/${_add_external_package_arg_NAME}")
        file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/_external/${_add_external_package_arg_NAME}")
    endif ()
    execute_process(
            COMMAND
            "${CMAKE_COMMAND}"
            ${_add_external_package_arg_CMAKE_ARGS}
            "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
            "-G"
            "${CMAKE_GENERATOR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/external/${_add_external_package_arg_NAME}"
            WORKING_DIRECTORY
            "${CMAKE_CURRENT_BINARY_DIR}/_external/${_add_external_package_arg_NAME}"
    )
    execute_process(
            COMMAND
            "${CMAKE_COMMAND}"
            "--build"
            "${CMAKE_CURRENT_BINARY_DIR}/_external/${_add_external_package_arg_NAME}"
    )
    execute_process(
            COMMAND
            "${CMAKE_COMMAND}"
            "--install"
            "${CMAKE_CURRENT_BINARY_DIR}/_external/${_add_external_package_arg_NAME}"
    )
endfunction()
