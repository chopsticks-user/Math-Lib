add_library(mathPrivateBase STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadPool.cpp
)

target_link_libraries(mathPrivateBase PUBLIC compilerFlags)