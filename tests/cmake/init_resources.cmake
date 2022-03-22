# copy basic.toml
add_custom_target(
        basic_toml
        DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.toml
)
add_custom_command(
        OUTPUT
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.toml
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.toml
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.toml ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.toml
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.toml ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.toml
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.toml ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.toml
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.toml ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.toml
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.toml
)
add_dependencies(tests basic_toml)

# copy basic.txt
add_custom_target(
        basic_txt
        DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.txt
)
add_custom_command(
        OUTPUT
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.txt ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/default/basic.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.txt ${CMAKE_CURRENT_SOURCE_DIR}/resources/example01/overwrite/basic.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.txt ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/default/basic.txt
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.txt ${CMAKE_CURRENT_SOURCE_DIR}/resources/example02/overwrite/basic.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/resources/basic.txt
)
add_dependencies(tests basic_toml basic_txt)
