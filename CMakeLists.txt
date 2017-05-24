cmake_minimum_required(VERSION 3.5)
project(sdl-cpp-wrapper)

set(CMAKE_CXX_STANDARD 14)

include(cmake/FindSDL2.cmake)

add_library(sdl-cpp
        include/sdl_cpp.h
        include/sdl_cpp_context.h
        include/sdl_cpp_event_key_state.h
        include/sdl_cpp_event_quit.h
        include/sdl_cpp_events.h
        include/sdl_cpp_exception.h
        include/sdl_cpp_renderer.h
        include/sdl_cpp_renderer_forward_declaration.h
        include/sdl_cpp_surface.h
        include/sdl_cpp_texture.h
        include/sdl_cpp_window.h
        src/sdl_cpp_event_key_state.cpp
        src/sdl_cpp_event_quit.cpp
        src/sdl_cpp_events.cpp
        )

target_include_directories(sdl-cpp SYSTEM PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${SDL2_INCLUDE_DIR}"
        )

target_link_libraries(sdl-cpp
        ${SDL2_LIBRARY}
        SDL2_image
        )

add_subdirectory(test-app)
