add_library(sdl-cpp-ttf
		include/sdl_cpp/fonts/ttf_font.h
		include/sdl_cpp/fonts/ttf_font_context.h
		src/fonts/ttf_font.cpp
		)


target_include_directories(sdl-cpp-ttf PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/include"
		)

target_include_directories(sdl-cpp-ttf SYSTEM PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
		"${SDL2_INCLUDE_DIR}"
		)

target_link_libraries(sdl-cpp-ttf PUBLIC
		sdl-cpp
		${SDL2_TTF_LIBRARY}
		)
