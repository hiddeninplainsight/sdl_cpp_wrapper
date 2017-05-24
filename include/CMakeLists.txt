
include(../cmake/FindSDL2.cmake)

add_library(sdl-cpp
        sdl_cpp_events.cpp
        sdl_cpp_event_quit.cpp
        )

target_include_directories(sdl-cpp SYSTEM PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
        "${SDL2_INCLUDE_DIR}"
        )

target_link_libraries(sdl-cpp
        ${SDL2_LIBRARY}
        SDL2_image
        )