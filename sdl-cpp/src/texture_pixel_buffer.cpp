#include "sdl_cpp/texture_pixel_buffer.h"
#include "sdl_cpp/sdl_exception.h"
#include <SDL2/SDL.h>
#include <cstddef>
#include <algorithm>

namespace sdl
{
	texture_pixel_buffer::texture_pixel_buffer(texture* t)
		: texture_ptr{t}
		, size{t->size()}
		, buffer{new buffer_type[size.width * size.height]}
	{
	}

	texture_pixel_buffer::~texture_pixel_buffer()
	{
		delete[] buffer;
	}

	void texture_pixel_buffer::clear(buffer_type colour)
	{
		size_t const buffer_size =
			static_cast<size_t>(size.width) * static_cast<size_t>(size.height);
		std::fill(buffer, buffer + buffer_size, colour);
	}

	void texture_pixel_buffer::update_texture() const
	{
		if (SDL_UpdateTexture(
				*texture_ptr, nullptr, buffer,
				size.width * static_cast<int>(sizeof(buffer_type))) != 0)
		{
			throw sdl_exception{"texture_pixel_buffer::update_texture",
								SDL_GetError()};
		}
	}
}
