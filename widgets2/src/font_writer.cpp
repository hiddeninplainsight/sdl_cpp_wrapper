#include "sdl_cpp/widgets2/font_writer.h"
#include "freetype_cpp/face.h"

namespace sdl
{
	namespace widgets2
	{
		void font_writer::set_pixel(int px, int py) const
		{
			if(px > 0 && px < pixels.size.width && py > 0 && py < pixels.size.height)
			{
				pixels.buffer[(py * pixels.size.width) + px] = 0xFFFFFFFF;
			}
		}

		void font_writer::draw_glyph(FT_GlyphSlot const &glyph)
		{
			auto p = glyph->bitmap.buffer;
			int const top = y - glyph->bitmap_top;
			int const left = x + glyph->bitmap_left;

			for(int cy = 0; cy < glyph->bitmap.rows; ++cy)
			{
				for(int cx = 0; cx < glyph->bitmap.width; ++cx)
				{
					if(*p)
					{
						int ox = cx + left;
						int oy = cy + top;
						set_pixel(ox, oy);
					}
					++p;
				}
			}
			x += glyph->advance.x >> 6;
		}
	}
}
