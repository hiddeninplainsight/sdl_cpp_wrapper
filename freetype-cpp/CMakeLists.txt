add_library(freetype-cpp
		src/face.cpp
		src/library.cpp

		include/freetype_cpp/internal/literal_parser.h
		include/freetype_cpp/internal/safetype.h

		include/freetype_cpp/face.h
		include/freetype_cpp/library.h
		include/freetype_cpp/points.h
		)

target_include_directories(freetype-cpp PUBLIC SYSTEM
		include
		)

target_link_libraries(freetype-cpp PUBLIC
		freetype
		)
