#ifndef SDL_CPP_RENDERER_H
#define SDL_CPP_RENDERER_H

#include <SDL2/SDL.h>
#include "renderer_forward_declaration.h"
#include "texture.h"
#include "window.h"

namespace sdl
{
    inline renderer::renderer(const window& window)
    {
        renderer_ptr = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if(renderer_ptr == nullptr)
            throw sdl_exception("renderer::renderer", SDL_GetError());
    }

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