#ifndef SDL_CPP_WRAPPER_FONT_WRITER_H
#define SDL_CPP_WRAPPER_FONT_WRITER_H

#include <freetype_cpp/face.h>
#include <freetype_cpp/draw_glyph_callback.h>
#include <sdl_cpp/pixel_buffer_painter.h>

namespace sdl
{
	namespace widgets2
	{
		class font_writer : public freetype_cpp::draw_glyph_callback
		{
		public:
			sdl::pixel_buffer_painter& pixels;
			long x{0};
			long y{0};

			explicit font_writer(sdl::pixel_buffer_painter& pixels)
				: pixels{pixels}
			{
			}

			void set_pixel(int px, int py) const;
			void draw_glyph(FT_Bitmap const& bitmap, FT_Int left, FT_Int top,
							FT_Vector advance) override;
		};
	}
}

#endif //SDL_CPP_WRAPPER_FONT_WRITER_H
