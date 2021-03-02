#ifndef FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H
#define FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include "draw_glyph_callback.h"

#include <memory>

namespace freetype_cpp
{
	class glyph;

	class bitmap_glyph
	{
	private:
		std::shared_ptr<glyph> glyph_ptr;
		FT_BitmapGlyph bitmap_object{nullptr};
		FT_Vector advance;

		explicit bitmap_glyph(std::shared_ptr<glyph> glyph_ptr);

	public:
		~bitmap_glyph();
		bitmap_glyph(bitmap_glyph const&) = delete;
		bitmap_glyph operator=(bitmap_glyph const&) = delete;

		static std::shared_ptr<bitmap_glyph> initialise_from_glyph(
			std::shared_ptr<glyph> glyph_ptr);

		void draw(draw_glyph_callback& callback);

		FT_Pos width() const { return advance.x; }
	};
}

#endif	// FREETYPE_CPP_FREETYPE_BITMAP_GLYPH_H
