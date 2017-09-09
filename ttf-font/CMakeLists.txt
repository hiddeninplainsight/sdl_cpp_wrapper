
project(sdl-cpp-ttf-font)

add_library(sdl-cpp-ttf-font INTERFACE
        )

target_include_directories(sdl-cpp SYSTEM INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/include"
        )

target_link_libraries(sdl-cpp-ttf-font INTERFACE
        sdl-cpp
        SDL2_ttf
        )
