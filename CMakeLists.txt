cmake_minimum_required(VERSION 3.19.1)  	# CMake version check
project(DiffCpp)	               		# Create project "simple_example"

set(CMAKE_CXX_STANDARD 14)            		# Enable c++14 standard
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/${PROJECT_NAME}")

#add_subdirectory(src)
add_subdirectory(test)
