#ifndef SDL_CPP_RENDER_TO_TEXTURE_H
#define SDL_CPP_RENDER_TO_TEXTURE_H

#include "renderer.h"
#include "texture.h"

namespace sdl
{
	class render_to_texture
	{
	private:
		renderer* renderer_to_redirect;

	public:
		render_to_texture(renderer* renderer_to_redirect, texture& targetTexture)
			: renderer_to_redirect{renderer_to_redirect}
		{
			renderer_to_redirect->set_target(targetTexture);
		}

		~render_to_texture()
		{
			renderer_to_redirect->clear_target();
		}

		render_to_texture(render_to_texture const&) = delete;
	};
}

#endif //SDL_CPP_RENDER_TO_TEXTURE_H
