add_executable(widgets2-demo-app
		main.cpp
		)

target_link_libraries(widgets2-demo-app PUBLIC
		widgets2
		)

copy_sdl2_windows_dlls("${sdl-cpp-wrapper_BINARY_DIR}/widgets2-demo-app")
