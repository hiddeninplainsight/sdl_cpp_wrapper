cmake_minimum_required(VERSION 3.5)
project(sdl-cpp-wrapper VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)

if(${UNIX})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
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

if(${WIN32})
	set(WIDGETS_EXECUTABLE_PATH_SOURCE_FILE src/widgets/executable_path_windows.cpp)
endif(${WIN32})

if(${UNIX})
	set(WIDGETS_EXECUTABLE_PATH_SOURCE_FILE src/widgets/executable_path_linux.cpp)
endif(${UNIX})

add_library(sdl-cpp
	include/sdl_cpp/sdl_cpp.h
	include/sdl_cpp/bezier.h
	include/sdl_cpp/collision_detection.h
	include/sdl_cpp/context.h
	include/sdl_cpp/event_keys.h
	include/sdl_cpp/event_mouse_dispatch.h
	include/sdl_cpp/event_quit.h
	include/sdl_cpp/events.h
	include/sdl_cpp/sdl_exception.h
	include/sdl_cpp/key_state.h
	include/sdl_cpp/lerp.h
	include/sdl_cpp/maths.h
	include/sdl_cpp/mouse_state.h
	include/sdl_cpp/point_transforms.h
	include/sdl_cpp/rectangle_collider.h
	include/sdl_cpp/render_to_texture.h
	include/sdl_cpp/renderer.h
	include/sdl_cpp/renderer_forward_declaration.h
	include/sdl_cpp/surface.h
	include/sdl_cpp/texture.h
	include/sdl_cpp/window.h
	src/bezier.cpp
	src/collision_detection.cpp
	src/event_keys.cpp
	src/event_mouse_dispatch.cpp
	src/event_quit.cpp
	src/events.cpp
	src/key_state.cpp
	src/lerp.cpp
	src/maths.cpp
	src/mouse_state.cpp
	src/point_transforms.cpp
	src/rectangle_collider.cpp

	# fonts
	include/sdl_cpp/fonts/ttf_font.h
	include/sdl_cpp/fonts/ttf_font_context.h
	src/fonts/ttf_font.cpp

	# widgets
	include/sdl_cpp/widgets/application.h
	include/sdl_cpp/widgets/button.h
	include/sdl_cpp/widgets/default_font.h
	include/sdl_cpp/widgets/executable_path.h
	include/sdl_cpp/widgets/image.h
	include/sdl_cpp/widgets/key.h
	include/sdl_cpp/widgets/label.h
	include/sdl_cpp/widgets/lines_no_storage.h
	include/sdl_cpp/widgets/resizable_widget.h
	include/sdl_cpp/widgets/widget.h
	include/sdl_cpp/widgets/widgets.h
	include/sdl_cpp/widgets/window_application.h
	src/widgets/application.cpp
	src/widgets/button.cpp
	src/widgets/default_font.cpp
	${WIDGETS_EXECUTABLE_PATH_SOURCE_FILE}
	src/widgets/image.cpp
	src/widgets/key.cpp
	src/widgets/label.cpp
	src/widgets/lines_no_storage.cpp
	src/widgets/widget.cpp
	src/widgets/window_application.cpp
	)

target_include_directories(sdl-cpp PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/include"
	)

target_include_directories(sdl-cpp SYSTEM PUBLIC
	"${CMAKE_CURRENT_LIST_DIR}/include"
	"${SDL2_INCLUDE_DIR}"
	)

target_link_libraries(sdl-cpp
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARY}
	${SDL2_TTF_LIBRARY}
	)

add_subdirectory(test-app)
add_subdirectory(tests)

install(TARGETS sdl-cpp ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include
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
