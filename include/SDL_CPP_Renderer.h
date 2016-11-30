#ifndef SDL_CPP_RENDERER_H
#define SDL_CPP_RENDERER_H

#include <SDL2/SDL.h>
#include "SDL_CPP_Renderer_forward_declaration.h"
#include "SDL_CPP_Texture.h"

namespace SDL
{
    inline void Renderer::Copy(const Texture& texture)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }

    inline void Renderer::Copy(const Texture& texture, const SDL_Rect& destination)
    {
        SDL_RenderCopy(renderer, texture, NULL, &destination);
    }

    inline void Renderer::Copy(const Texture& texture, int x, int y)
    {
        auto destination = texture.Dimensions();
        destination.x = x;
        destination.y = y;
        SDL_RenderCopy(renderer, texture, NULL, &destination);
    }
}

#endif //SDL_CPP_RENDERER_H
