cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(FPSBypass VERSION 1.0.0 LANGUAGES OBJCXX CXX)

# Use GLOB_RECURSE instead of GLOB
# to recursively add all source files 
# under src/ 
file(GLOB SOURCES
	src/*.cpp
	src/*.mm
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	if (NOT DEFINED ENV{GEODE_SDK})
	    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
	else()
	    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
	endif()

	set(GEODE_LINK_NIGHTLY ON)
	add_subdirectory($ENV{GEODE_SDK} $ENV{GEODE_SDK}/build)
endif()


# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_NAME} geode-sdk "-framework OpenGL")
create_geode_file(${PROJECT_NAME})
