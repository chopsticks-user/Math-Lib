add_library(mathPrivateSpatial STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Tensor.cpp
)

target_include_directories(mathPrivateSpatial PUBLIC 
    ${PROJECT_SOURCE_DIR}/Source/Private
)

target_link_libraries(mathPrivateSpatial PRIVATE 
    mathPrivateBase
)