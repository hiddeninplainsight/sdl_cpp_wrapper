#ifndef FREETYPE_CPP_FREETYPE_GET_GLYPH_CALLBACK_H
#define FREETYPE_CPP_FREETYPE_GET_GLYPH_CALLBACK_H

#include <ft2build.h>
#include FT_FREETYPE_H

namespace freetype_cpp
{
	class get_glyph_callback
	{
	public:
		virtual ~get_glyph_callback() = default;

		virtual void receive_glyph(FT_GlyphSlot const& glyph_slot) = 0;
	};
}

#endif	// FREETYPE_CPP_FREETYPE_GET_GLYPH_CALLBACK_H
