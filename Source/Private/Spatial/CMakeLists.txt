add_library(mathPrivateSpatial STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Tensor.cpp
)

target_link_libraries(mathPrivateSpatial PRIVATE 
    mathPrivateBase
)