add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Base)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Integration)

add_library(mathPrivate INTERFACE)

target_link_libraries(mathPrivate INTERFACE
    mathPrivateBase
    mathPrivateIntegration
)
