
include(../cmake/FindSDL2.cmake)

add_library(sdl-cpp INTERFACE)

target_include_directories(sdl-cpp INTERFACE SYSTEM
        ${CMAKE_CURRENT_LIST_DIR}
        ${SDL2_INCLUDE_DIR}
        )

target_link_libraries(sdl-cpp INTERFACE
        ${SDL2_LIBRARY}
        SDL2_image
        )