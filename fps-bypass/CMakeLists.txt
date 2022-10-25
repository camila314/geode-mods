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

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_NAME} geode-sdk "-framework OpenGL")
create_geode_file(${PROJECT_NAME})
