#ifndef SDL_CPP_RENDERER_CLIP_REGION_H
#define SDL_CPP_RENDERER_CLIP_REGION_H

#include "renderer_forward_declaration.h"

namespace sdl
{
	class renderer_clip_region
	{
	private:
		renderer const* renderer_ptr;
		bool const was_clipped;
		SDL_Rect original_region;
	public:
		renderer_clip_region(renderer const* renderer_ptr, SDL_Rect const& region);
		~renderer_clip_region();
		renderer_clip_region(renderer_clip_region const&) = delete;
	};
}

#endif	// SDL_CPP_WRAPPER_RENDERER_CLIP_REGION_H
