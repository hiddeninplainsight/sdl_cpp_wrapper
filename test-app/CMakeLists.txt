
project(sdl-cpp-wrapper-test-app)

add_executable(test-app
        main.cpp
        )

target_link_libraries(test-app
        sdl-cpp
		widgets
        )

file(COPY circle.png
        DESTINATION ${sdl-cpp-wrapper-test-app_BINARY_DIR})

file(COPY Press_Start_2P/PressStart2P-Regular.ttf
        DESTINATION ${sdl-cpp-wrapper-test-app_BINARY_DIR})

copy_sdl2_windows_dlls("${sdl-cpp-wrapper_BINARY_DIR}/test-app")
