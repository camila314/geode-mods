cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(Stuff VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child} AND NOT ${child} MATCHES "^(build|\\..+)$")
        add_subdirectory(${child})
    endif()
endforeach()
