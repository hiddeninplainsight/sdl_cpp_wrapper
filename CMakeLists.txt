cmake_minimum_required(VERSION 3.5)

# detect if sdl_cpp_wrapper is being included as a sub project
if(NOT DEFINED PROJECT_NAME)
	set(NOT_SUB_PROJECT ON)
endif()

project(sdl-cpp-wrapper VERSION 0.0.1)

if(NOT_SUB_PROJECT)
	set(CMAKE_CXX_STANDARD 14)

	if(${UNIX})
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
	endif()
endif()

macro(set_SDL2_Windows_variables)
	if(${WIN32})
		if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64-bit build
			set(SDL2_WINDOWS_LIBRARY_DIRECTORY "${sdl-cpp-wrapper_SOURCE_DIR}/sdl2windows/lib/x64")
		else(CMAKE_SIZEOF_VOID_P EQUAL 8) # 32-bit build
			set(SDL2_WINDOWS_LIBRARY_DIRECTORY "${sdl-cpp-wrapper_SOURCE_DIR}/sdl2windows/lib/x86")
		endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

		set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/sdl2windows/include")

		set(SDL2 "${SDL2_WINDOWS_LIBRARY_DIRECTORY}")
		link_directories("${SDL2_WINDOWS_LIBRARY_DIRECTORY}/")
	endif()
endmacro()

function(copy_sdl2_windows_dlls target_path)
	if(${WIN32})
		set_SDL2_Windows_variables()
		message(STATUS "Copying SDL2 DLLs to '${target_path}' from '${SDL2_WINDOWS_LIBRARY_DIRECTORY}/*.dll'")
		file(GLOB dll_files "${SDL2_WINDOWS_LIBRARY_DIRECTORY}/*.dll")
		foreach(dll_file ${dll_files})
			file(COPY "${dll_file}" DESTINATION "${target_path}")
		endforeach()
	endif()
endfunction()

set_SDL2_Windows_variables()
include(cmake/FindSDL2.cmake)

find_library(SDL2_IMAGE_LIBRARY SDL2_image
	HINTS
	${SDL2})

find_library(SDL2_TTF_LIBRARY SDL2_ttf
	HINTS
	${SDL2})

add_subdirectory(sdl-cpp)
add_subdirectory(widgets)
add_subdirectory(widgets2)
add_subdirectory(widgets2-demo-app)

if(NOT_SUB_PROJECT)
	add_subdirectory(test-app)
endif()
add_subdirectory(tests)

install(TARGETS sdl-cpp ARCHIVE DESTINATION lib)
install(DIRECTORY sdl-cpp/include/ DESTINATION include
	FILES_MATCHING PATTERN "*.h")

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A object-oriented wrapper for libSDL")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_LIST_DIR}/install/description.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_LIST_DIR}/install/license.txt")

set(CPACK_PACKAGE_VERSION_MAJOR ${sdl-cpp-wrapper_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${sdl-cpp-wrapper_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${sdl-cpp-wrapper_VERSION_PATCH})

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Byran Wills-Heath <byran@adgico.co.uk>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libsdl2-dev (>=2.0.0), libsdl2-image-dev (>=2.0.1), libsdl2-ttf-dev (>=2.0.14)")
set(CPACK_DEBIAN_PACKAGE_SECTION "Development")

include(CPack)
