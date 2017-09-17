cmake_minimum_required(VERSION 3.5)
project(sdl-cpp-wrapper VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 14)

if(${UNIX})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

include(cmake/FindSDL2.cmake)

add_library(sdl-cpp
        include/sdl_cpp/sdl_cpp.h
        include/sdl_cpp/collision_detection.h
        include/sdl_cpp/context.h
        include/sdl_cpp/event_keys.h
        include/sdl_cpp/event_mouse_dispatch.h
        include/sdl_cpp/event_quit.h
        include/sdl_cpp/events.h
        include/sdl_cpp/sdl_exception.h
        include/sdl_cpp/key_state.h
        include/sdl_cpp/maths.h
        include/sdl_cpp/mouse_state.h
        include/sdl_cpp/point_transforms.h
        include/sdl_cpp/rectangle_collider.h
        include/sdl_cpp/renderer.h
        include/sdl_cpp/renderer_forward_declaration.h
        include/sdl_cpp/surface.h
        include/sdl_cpp/texture.h
        include/sdl_cpp/window.h
        src/collision_detection.cpp
        src/event_keys.cpp
        src/event_mouse_dispatch.cpp
        src/event_quit.cpp
        src/events.cpp
        src/key_state.cpp
        src/maths.cpp
        src/mouse_state.cpp
        src/point_transforms.cpp
        src/rectangle_collider.cpp

        # fonts
        include/sdl_cpp/fonts/ttf_font.h
        include/sdl_cpp/fonts/ttf_font_context.h

        # widgets
        include/sdl_cpp/widgets/default_font.h
        include/sdl_cpp/widgets/application.h
        include/sdl_cpp/widgets/label.h
        include/sdl_cpp/widgets/resizable_widget.h
        include/sdl_cpp/widgets/widget.h
        include/sdl_cpp/widgets/window_application.h
        src/widgets/default_font.cpp
        src/widgets/application.cpp
        src/widgets/label.cpp
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
        SDL2_image
        SDL2_ttf
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
