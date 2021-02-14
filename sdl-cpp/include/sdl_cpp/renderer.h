#ifndef SDL_CPP_RENDERER_H
#define SDL_CPP_RENDERER_H

#include <SDL2/SDL.h>
#include "renderer_forward_declaration.h"
#include "texture.h"
#include "window.h"

namespace sdl
{
	inline renderer::renderer(const window& window, bool vSync)
	{
		renderer_ptr = SDL_CreateRenderer(
			window, -1, SDL_RENDERER_ACCELERATED |
				(vSync ? SDL_RENDERER_PRESENTVSYNC : 0));

		if (renderer_ptr == nullptr)
			throw sdl_exception("renderer::renderer", SDL_GetError());
	}

	inline void renderer::copy(const texture& texture)
	{
		SDL_RenderCopy(renderer_ptr, texture, NULL, NULL);
	}

	inline void renderer::copy(const texture& texture,
							   const SDL_Rect& destination)
	{
		SDL_Rect source = destination;
		source.x = 0;
		source.y = 0;
		SDL_RenderCopy(renderer_ptr, texture, &source, &destination);
	}

	inline void renderer::copy(const texture& texture, int x, int y)
	{
		auto destination = texture.dimensions();
		destination.x = x;
		destination.y = y;
		SDL_RenderCopy(renderer_ptr, texture, NULL, &destination);
	}

	inline void renderer::set_target(texture& texture)
	{
		SDL_SetRenderTarget(renderer_ptr, texture);
	}
}

#endif  // SDL_CPP_RENDERER_H
