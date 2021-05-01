add_executable(
	DiffCpp
	diff.cpp
)

add_custom_command(TARGET DiffCpp 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:DiffCpp> ../)
