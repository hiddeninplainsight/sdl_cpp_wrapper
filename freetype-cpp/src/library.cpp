#include "freetype_cpp/library.h"
#include "freetype_cpp/freetype_exception.h"

using namespace std;

namespace freetype_cpp
{
	library::library()
	{
		FT_Error error = FT_Init_FreeType(&library_object);
		if (error)
		{
			throw freetype_exception{};
		}
	}

	library::~library() { FT_Done_FreeType(library_object); }

	shared_ptr<library> library::initialise_instance()
	{
		return std::shared_ptr<library>{new library{}};
	}
}  // namespace freetype_cpp
