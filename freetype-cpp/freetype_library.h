#ifndef SDL_CPP_FREETYPE_LIBRARY_H
#define SDL_CPP_FREETYPE_LIBRARY_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include <memory>

class freetype_library
{
private:
	FT_Library  library;

	freetype_library();
public:
	static std::shared_ptr<freetype_library> initialise_instance();
};

#endif	// SDL_CPP_FREETYPE_LIBRARY_H
