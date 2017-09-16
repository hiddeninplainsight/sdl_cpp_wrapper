cmake_minimum_required(VERSION 3.5)
project(sdl-cpp-wrapper)

set(CMAKE_CXX_STANDARD 14)

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

        # ttf_font
        include/sdl_cpp/ttf_font/ttf_font.h
        include/sdl_cpp/ttf_font/ttf_font_context.h

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

target_include_directories(sdl-cpp PUBLIC
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
