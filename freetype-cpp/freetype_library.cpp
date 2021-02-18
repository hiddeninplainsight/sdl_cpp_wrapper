#include "freetype_library.h"
#include <exception>

freetype_library::freetype_library()
{
	FT_Error error = FT_Init_FreeType( &library );
	if (error)
	{
		throw std::exception();
	}
}

std::shared_ptr<freetype_library> freetype_library::initialise_instance()
{
	return std::shared_ptr<freetype_library>{new freetype_library{}};
}
