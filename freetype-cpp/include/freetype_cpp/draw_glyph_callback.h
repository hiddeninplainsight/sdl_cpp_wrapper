#ifndef FREETYPE_CPP_FREETYPE_DRAW_GLYPH_CALLBACK_H
#define FREETYPE_CPP_FREETYPE_DRAW_GLYPH_CALLBACK_H

#include <ft2build.h>
#include FT_FREETYPE_H

namespace freetype_cpp
{
	class draw_glyph_callback
	{
	public:
		virtual ~draw_glyph_callback() = default;

		virtual void draw_glyph(FT_Bitmap const& bitmap, FT_Int left,
								FT_Int top, FT_Vector advance) = 0;
	};
}

#endif	// FREETYPE_CPP_FREETYPE_DRAW_GLYPH_CALLBACK_H
