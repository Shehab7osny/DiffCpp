# Add main.cpp file of project root directory as source file
set(SOURCE_FILES diff.cpp)

install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
