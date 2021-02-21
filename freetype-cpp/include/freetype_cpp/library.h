#ifndef FREETYPE_CPP_FREETYPE_LIBRARY_H
#define FREETYPE_CPP_FREETYPE_LIBRARY_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include <memory>

namespace freetype_cpp
{
	class library
	{
		friend class face;
	private:
		FT_Library library_object;

		library();

	public:
		~library();
		library(library const&) = delete;
		library& operator=(library const&) = delete;

		static std::shared_ptr<library> initialise_instance();
	};
}  // namespace freetype_cpp

#endif	// FREETYPE_CPP_FREETYPE_LIBRARY_H
