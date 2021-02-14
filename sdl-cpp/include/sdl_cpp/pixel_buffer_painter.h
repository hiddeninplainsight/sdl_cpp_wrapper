#ifndef SDL_CPP_PIXEL_BUFFER_PAINTER_H
#define SDL_CPP_PIXEL_BUFFER_PAINTER_H

#include <SDL2/SDL.h>
#include "sdl_size.h"
#include "texture_pixel_buffer.h"

namespace sdl
{
	class pixel_buffer_painter
	{
	public:
		using buffer_type = Uint32;
		sdl_size const size;
		buffer_type* const buffer;

		pixel_buffer_painter(sdl_size const& size, buffer_type* buffer)
			: size{size}
			, buffer{buffer}
		{
		}

		static pixel_buffer_painter from_texture_pixel_buffer(
			texture_pixel_buffer const& pixel_buffer)
		{
			return pixel_buffer_painter{pixel_buffer.size, pixel_buffer.buffer};
		}

	protected:
		bool range_check(int& x, int& y, int& width, int& height) const;

	public:
		void filled_rectangle(int x, int y, int width, int height,
							  buffer_type colour) const;

		void filled_circle(int center_x, int center_y, int radius,
						   buffer_type colour) const;
		void circle(int center_x, int center_y, int radius, buffer_type colour,
					int line_width = 1) const;
	};
}

#endif	// SDL_CPP_PIXEL_BUFFER_PAINTER_H
