if(${WIN32})
	set(WIDGETS_EXECUTABLE_PATH_SOURCE_FILE src/executable_path_windows.cpp)
endif(${WIN32})

if(${UNIX})
	set(WIDGETS_EXECUTABLE_PATH_SOURCE_FILE src/executable_path_linux.cpp)
endif(${UNIX})

add_library(widgets
		include/sdl_cpp/widgets/application.h
		include/sdl_cpp/widgets/button.h
		include/sdl_cpp/widgets/default_font.h
		include/sdl_cpp/widgets/executable_path.h
		include/sdl_cpp/widgets/image.h
		include/sdl_cpp/widgets/key.h
		include/sdl_cpp/widgets/label.h
		include/sdl_cpp/widgets/lines_no_storage.h
		include/sdl_cpp/widgets/resizable_widget.h
		include/sdl_cpp/widgets/widget.h
		include/sdl_cpp/widgets/widgets.h
		include/sdl_cpp/widgets/window_application.h
		src/application.cpp
		src/button.cpp
		src/default_font.cpp
		${WIDGETS_EXECUTABLE_PATH_SOURCE_FILE}
		src/image.cpp
		src/key.cpp
		src/label.cpp
		src/lines_no_storage.cpp
		src/widget.cpp
		src/window_application.cpp
		)

target_include_directories(widgets PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_include_directories(widgets SYSTEM PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_link_libraries(widgets PUBLIC
		sdl-cpp
		)
