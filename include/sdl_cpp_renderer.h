#ifndef SDL_CPP_RENDERER_H
#define SDL_CPP_RENDERER_H

#include <SDL2/SDL.h>
#include "sdl_cpp_renderer_forward_declaration.h"
#include "sdl_cpp_texture.h"

namespace sdl
{
    inline void renderer::copy(const texture& texture)
    {
        SDL_RenderCopy(renderer_ptr, texture, NULL, NULL);
    }

    inline void renderer::copy(const texture& texture, const SDL_Rect& destination)
    {
        SDL_RenderCopy(renderer_ptr, texture, NULL, &destination);
    }

    inline void renderer::copy(const texture& texture, int x, int y)
    {
        auto destination = texture.dimensions();
        destination.x = x;
        destination.y = y;
        SDL_RenderCopy(renderer_ptr, texture, NULL, &destination);
    }
}

#endif //SDL_CPP_RENDERER_H
