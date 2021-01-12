add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  ${PROJECT_NAME}Test.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest pthread)
