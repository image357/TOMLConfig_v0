find_package(
        Doxygen
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia
)

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_UML_LOOK YES)

doxygen_add_docs(
        docs
        src
        include/${CMAKE_PROJECT_NAME}
        ALL
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
