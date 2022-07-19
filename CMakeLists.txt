cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(Stuff VERSION 0.1.0 LANGUAGES CXX)

add_custom_target(Stuff)

file(GLOB projects "*/mod.json")

foreach(proj ${projects})
	get_filename_component(proj_root ${proj} DIRECTORY)
	add_subdirectory(${proj_root})
endforeach()
