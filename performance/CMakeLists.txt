set(BINARY ${CMAKE_PROJECT_NAME}_BENCH)

file(GLOB_RECURSE BENCH_SOURCES LIST_DIRECTORIES false *.cpp)

set(SOURCES ${BENCH_SOURCES})

add_executable(${BINARY} ${BENCH_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib benchmark::benchmark)