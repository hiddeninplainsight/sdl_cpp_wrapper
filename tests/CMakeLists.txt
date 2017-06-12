
project(sdl-cpp-wrapper-tests)

add_executable(tests
        collision_detection_tests.cpp
        )

target_link_libraries(tests
        sdl-cpp)
