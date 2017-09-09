
add_library(sdl-cpp-widgets
        include/sdl_cpp_widgets_application.h
        include/sdl_cpp_widgets_window_application.h
        src/sdl_cpp_widgets_application.cpp
        src/sdl_cpp_widgets_window_application.cpp
        )

target_include_directories(sdl-cpp-widgets SYSTEM PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include"
        )

target_link_libraries(sdl-cpp-widgets PUBLIC
        sdl-cpp
        sdl-cpp-ttf-font
        )
