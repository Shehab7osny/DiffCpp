cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLGAS "${CMAKE_CXX_FLAGS} ${extra_flags}")

project(DiffCpp)

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)
