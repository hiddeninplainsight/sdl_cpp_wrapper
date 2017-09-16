#ifndef SDL_CPP_TEXTURE_H
#define SDL_CPP_TEXTURE_H

#include <SDL2/SDL.h>
#include "renderer_forward_declaration.h"
#include "sdl_exception.h"
#include "surface.h"

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

        ~texture()
        {
            if(texture_ptr != nullptr)
                SDL_DestroyTexture(texture_ptr);
        }

        texture(const texture&) = delete;
        texture& operator=(const texture&) = delete;

        texture(texture&& other) noexcept
        {
            texture_ptr = other.texture_ptr;
            other.texture_ptr = nullptr;
        }

        texture& operator=(texture&& other) noexcept
        {
            if(texture_ptr != nullptr)
                SDL_DestroyTexture(texture_ptr);

            texture_ptr = other.texture_ptr;
            other.texture_ptr = nullptr;

            return *this;
        }

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

/*
@startuml
namespace sdl {
    class texture {
        + texture(const renderer& renderer, const surface& surface)
        + operator SDL_Texture*() const
        + SDL_Rect dimensions() const
    }

    texture --> sdl_exception
    texture --> renderer
    texture --> surface
    context .. texture : <<must exist>> <
}
@enduml
*/

#endif //SDL_CPP_TEXTURE_H
