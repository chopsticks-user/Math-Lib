add_library(mathPrivateBase STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Util/Random.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Util/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Util/ThreadPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/Function.cpp
)

target_include_directories(mathPrivateBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Def
)

target_link_libraries(mathPrivateBase PUBLIC compilerFlags)