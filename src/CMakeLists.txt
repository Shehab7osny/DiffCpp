# Add main.cpp file of project root directory as source file
set(SOURCE_FILES diff.cpp)

add_library(${PROJECT_NAME} SHARED
  ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
  pthread)

