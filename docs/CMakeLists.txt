find_package(
        Doxygen
        REQUIRED
        doxygen
        dot
)

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_UML_LOOK YES)

doxygen_add_docs(
        docs
        src
        include
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
