#ifndef SDL_CPP_TEXTURE_H
#define SDL_CPP_TEXTURE_H

#include <SDL2/SDL.h>
#include "sdl_cpp_renderer_forward_declaration.h"
#include "sdl_cpp_exception.h"
#include "sdl_cpp_surface.h"

namespace sdl
{
    class texture
    {
    private:
        SDL_Texture* texture_ptr;
    public:
        texture(const renderer& renderer, const surface& surface)
        {
            texture_ptr = SDL_CreateTextureFromSurface(renderer, surface);
            if(texture_ptr == nullptr)
                throw sdl_exception("texture::texture", SDL_GetError());
        }

        ~texture() { SDL_DestroyTexture(texture_ptr); }

        texture(const texture&) = delete;
        texture& operator=(const texture&) = delete;

        operator SDL_Texture*() const { return texture_ptr; }

        SDL_Rect dimensions() const
        {
            SDL_Rect rectangle;
            rectangle.x = 0;
            rectangle.y = 0;
            SDL_QueryTexture(texture_ptr, nullptr, nullptr, &rectangle.w, &rectangle.h);
            return rectangle;
        }
    };
}

#endif //SDL_CPP_TEXTURE_H
