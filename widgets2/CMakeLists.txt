add_library(widgets2
		include/sdl_cpp/widgets2/application.h
		include/sdl_cpp/widgets2/forward_declarations.h
		include/sdl_cpp/widgets2/label.h
		include/sdl_cpp/widgets2/panel.h
		include/sdl_cpp/widgets2/widget.h
		include/sdl_cpp/widgets2/widget_container.h
		include/sdl_cpp/widgets2/window.h
		include/sdl_cpp/widgets2/window_flags.h

		src/application.cpp
		src/label.cpp
		src/panel.cpp
		src/widget.cpp
		src/widget_container.cpp
		src/window.cpp
		)

target_include_directories(widgets2 PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_include_directories(widgets2 SYSTEM PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_link_libraries(widgets2 PUBLIC
		sdl-cpp
		freetype-cpp::freetype
		freetype-cpp::fonts
		)
