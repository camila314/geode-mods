cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(alignto VERSION 1.0.0)

file(GLOB SOURCES
	src/*.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    if (NOT DEFINED ENV{GEODE_SDK})
        message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
    else()
        message(STATUS "Found Geode: $ENV{GEODE_SDK}")
    endif()

    set(GEODE_LINK_NIGHTLY On)
    add_subdirectory($ENV{GEODE_SDK} $ENV{GEODE_SDK}/build)
endif()

target_link_libraries(${PROJECT_NAME} geode-sdk)
create_geode_file(${PROJECT_NAME})
