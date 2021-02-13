#include "sdl_cpp/renderer_clip_region.h"
#include <SDL2/SDL.h>

namespace sdl
{
	renderer_clip_region::renderer_clip_region(const renderer* renderer_ptr, SDL_Rect const& region)
		: renderer_ptr{renderer_ptr}
		, was_clipped{SDL_RenderIsClipEnabled(*renderer_ptr) == SDL_TRUE}
	{
		if(was_clipped)
		{
			SDL_RenderGetClipRect(*renderer_ptr, &original_region);
		}

		SDL_RenderSetClipRect(*renderer_ptr, &region);
	}

	renderer_clip_region::~renderer_clip_region()
	{
		SDL_Rect const* rect = was_clipped ? &original_region : nullptr;
		SDL_RenderSetClipRect(*renderer_ptr, rect);
	}
}
