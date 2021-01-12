cmake_minimum_required(VERSION 3.19.1)  	# CMake version check
project(DiffCpp)	               		# Create project "simple_example"

set(CMAKE_CXX_STANDARD 14)            		# Enable c++14 standard
set(CMAKE_CXX_FLGAS "${CMAKE_CXX_FLAGS} ${extra_flags}")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/${PROJECT_NAME}")

add_subdirectory(src)
add_subdirectory(test)
