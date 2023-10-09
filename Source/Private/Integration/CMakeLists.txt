add_library(mathPrivateIntegration STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/GaussKronrod.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MonteCarlo.cpp
)

target_include_directories(mathPrivateIntegration PUBLIC
    ${PROJECT_SOURCE_DIR}/Source/Private
)

target_link_libraries(mathPrivateIntegration 
    PUBLIC compilerFlags
    PRIVATE mathPrivateBase
)