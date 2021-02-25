#include "sdl_cpp/widgets2/font_writer.h"
#include "freetype_cpp/face.h"

namespace sdl
{
	namespace widgets2
	{
		void font_writer::set_pixel(int px, int py) const
		{
			if (px > 0 && px < pixels.size.width && py > 0 &&
				py < pixels.size.height)
			{
				pixels.buffer[(py * pixels.size.width) + px] = 0xFFFFFFFF;
			}
		}

		void font_writer::draw_glyph(FT_Bitmap const& bitmap, FT_Int bitmap_left,
									 FT_Int bitmap_top, FT_Vector advance)
		{
			auto p = bitmap.buffer;
			int const top = y - bitmap_top;
			int const left = x + bitmap_left;

			for (int cy = 0; cy <bitmap.rows; ++cy)
			{
				for (int cx = 0; cx < bitmap.width; ++cx)
				{
					if (*p)
					{
						int ox = cx + left;
						int oy = cy + top;
						set_pixel(ox, oy);
					}
					++p;
				}
			}
			x += advance.x >> 6;
		}
	}
}
