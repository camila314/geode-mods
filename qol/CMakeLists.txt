cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(QoL VERSION 1.0.0)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

find_path(GEODE_SDK_PATH
  NAMES Geode.cmake
  PATHS $ENV{GEODE_SUITE}/sdk /Users/Shared/Geode/suite/sdk /usr/local/geode/sdk
  DOC "Geode SDK path."
  REQUIRED
)
include(${GEODE_SDK_PATH}/Geode.cmake)

setup_geode_mod()