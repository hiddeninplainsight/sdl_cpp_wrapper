
include(../cmake/FindSDL2.cmake)

add_library(sdl-cpp
        sdl_cpp.h
        sdl_cpp_context.h
        sdl_cpp_event_key_state.cpp
        sdl_cpp_event_key_state.h
        sdl_cpp_event_quit.cpp
        sdl_cpp_event_quit.h
        sdl_cpp_events.cpp
        sdl_cpp_events.h
        sdl_cpp_exception.h
        sdl_cpp_renderer.h
        sdl_cpp_renderer_forward_declaration.h
        sdl_cpp_surface.h
        sdl_cpp_texture.h
        sdl_cpp_window.h
        )

target_include_directories(sdl-cpp SYSTEM PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
        "${SDL2_INCLUDE_DIR}"
        )

target_link_libraries(sdl-cpp
        ${SDL2_LIBRARY}
        SDL2_image
        )