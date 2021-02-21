add_library(freetype-cpp
		src/face.cpp
		src/library.cpp

		include/freetype_cpp/internal/literal_parser.h
		include/freetype_cpp/internal/safetype.h

		include/freetype_cpp/face.h
		include/freetype_cpp/freetype_exception.h
		include/freetype_cpp/library.h
		include/freetype_cpp/points.h
		)

target_include_directories(freetype-cpp PUBLIC SYSTEM
		include
		)

target_link_libraries(freetype-cpp PUBLIC
		freetype
		)

add_library(freetype-cpp::freetype ALIAS freetype-cpp)

add_library(freetype-cpp-fonts
		fonts/PressStart2P_Regular_ttf.cpp
		fonts/PressStart2P_Regular_ttf.h
		)

target_include_directories(freetype-cpp-fonts PUBLIC SYSTEM
		fonts
		)

add_library(freetype-cpp::fonts ALIAS freetype-cpp-fonts)
