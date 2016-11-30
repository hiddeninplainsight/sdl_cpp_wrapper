#ifndef SDL_CPP_TEXTURE_H
#define SDL_CPP_TEXTURE_H

#include <SDL2/SDL.h>
#include "SDL_CPP_Renderer_forward_declaration.h"
#include "SDL_CPP_Exception.h"
#include "SDL_CPP_Surface.h"

namespace SDL
{
    class Texture
    {
    private:
        SDL_Texture* texture;
    public:
        Texture(const Renderer& renderer, const Surface& surface)
        {
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if(texture == nullptr)
                throw SDL_Exception("Texture::Texture", SDL_GetError());
        }

        ~Texture() { SDL_DestroyTexture(texture); }

        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;

        operator SDL_Texture*() const { return texture; }

        SDL_Rect Dimensions() const
        {
            SDL_Rect rectangle;
            rectangle.x = 0;
            rectangle.y = 0;
            SDL_QueryTexture(texture, nullptr, nullptr, &rectangle.w, &rectangle.h);
            return rectangle;
        }
    };
}

#endif //SDL_CPP_TEXTURE_H
