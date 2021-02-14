#ifndef SDL_CPP_TEXTURE_PIXEL_BUFFER_H
#define SDL_CPP_TEXTURE_PIXEL_BUFFER_H

#include <SDL2/SDL.h>
#include "texture.h"
#include "sdl_size.h"

namespace sdl
{
	class texture_pixel_buffer
	{
	public:
		using buffer_type = Uint32;
		texture* const texture_ptr;
		sdl_size const size;
		buffer_type* const buffer;

		explicit texture_pixel_buffer(texture* t);
		~texture_pixel_buffer();

		texture_pixel_buffer(texture_pixel_buffer const&) = delete;
		texture_pixel_buffer& operator=(texture_pixel_buffer const&) = delete;

		void clear(buffer_type colour = 0);
		void update_texture() const;
	};
}

#endif	// SDL_CPP_TEXTURE_PIXEL_BUFFER_H
