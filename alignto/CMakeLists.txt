cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(AlignTo VERSION 1.0.1)

file(GLOB SOURCES
    src/*.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

setup_geode_mod(${PROJECT_NAME})

CPMAddPackage("gh:camila314/UIBuilder#main")
target_link_libraries(${PROJECT_NAME} UIBuilder)
