cmake_minimum_required(VERSION 3.16)
project(DiffCpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLGAS "${CMAKE_CXX_FLAGS} ${extra_flags}")

include_directories(include)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

if (BUILD_TESTS)
	add_subdirectory(test)
	add_subdirectory(googletest)
endif()

if (BUILD_BENCH)
	add_subdirectory(benchmark)
	add_subdirectory(performance)
endif()