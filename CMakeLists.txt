cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(Stuff VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_custom_target(Stuff)

file(GLOB projects "*/mod.json")

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

set(GEODE_LINK_NIGHTLY ON)
add_subdirectory($ENV{GEODE_SDK} $ENV{GEODE_SDK}/build)

foreach(proj ${projects})
	get_filename_component(proj_root ${proj} DIRECTORY)
	add_subdirectory(${proj_root})
endforeach()
