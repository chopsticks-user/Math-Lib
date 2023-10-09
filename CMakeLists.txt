cmake_minimum_required(VERSION 3.15)

project(Math VERSION 1.0.0 LANGUAGES CXX)

include(CompilerFlags.cmake)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/Private)

add_executable(Application ${PROJECT_SOURCE_DIR}/Application.cpp)

target_link_libraries(Application
    PUBLIC mathPrivate
)