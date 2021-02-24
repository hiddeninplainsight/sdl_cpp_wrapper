#ifndef FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H
#define FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <memory>

namespace freetype_cpp
{
	class glyph;

	class bitmap_glyph
	{
	private:
		std::shared_ptr<glyph> glyph_ptr;
		FT_BitmapGlyph bitmap_object{nullptr};

		explicit bitmap_glyph(std::shared_ptr<glyph> glyph_ptr);

	public:
		~bitmap_glyph();
		bitmap_glyph(bitmap_glyph const&) = delete;
		bitmap_glyph operator=(bitmap_glyph const&) = delete;
	};
}

#endif	// FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H
