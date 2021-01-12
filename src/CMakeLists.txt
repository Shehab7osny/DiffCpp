# Add main.cpp file of project root directory as source file
set(SOURCE_FILES diff.cpp)

add_library(${PROJECT_NAME} SHARED
  ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
  pthread)

install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)