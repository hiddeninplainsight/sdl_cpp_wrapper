add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/build/out/lib/libfreetype.a
		COMMAND ./build-freetype.sh
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build-freetype.sh
		VERBATIM
		)

add_custom_target(freetype-build
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/out/lib/libfreetype.a
		)

add_library(freetype INTERFACE)

target_include_directories(freetype SYSTEM INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/build/out/include/freetype2
		)

add_dependencies(freetype
		freetype-build
		)

target_link_libraries(freetype INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/build/out/lib/libfreetype.a
		)
