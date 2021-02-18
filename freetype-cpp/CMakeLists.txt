add_library(freetype-cpp
		freetype_library.cpp
		freetype_library.h
		)

target_include_directories(freetype-cpp PUBLIC SYSTEM
		./
		)

target_link_libraries(freetype-cpp PUBLIC
		freetype
		)
