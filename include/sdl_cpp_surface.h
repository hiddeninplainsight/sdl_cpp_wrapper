#ifndef SDL_CPP_SURFACE_H
#define SDL_CPP_SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "sdl_cpp_exception.h"

namespace sdl
{
    class ttf_font;

    class surface
    {
        friend ttf_font;
    private:
        SDL_Surface *surface_ptr;

        explicit surface(SDL_Surface *surface_ptr)
                : surface_ptr{surface_ptr}
        {
        }
    public:
        static surface create_from_bitmap(const std::string& path)
        {
            surface bitmapSurface{SDL_LoadBMP(path.c_str())};
            if(bitmapSurface.surface_ptr == nullptr)
                throw sdl_exception("surface::CreateFromBitmap", SDL_GetError());

            return bitmapSurface;
        }

        static surface create_from_image(const std::string& path)
        {
            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);
            if((initted & flags) != flags)
                throw sdl_exception("surface::CreateFromImage - IMG_Init", IMG_GetError());

            surface imageSurface{IMG_Load(path.c_str())};
            if(imageSurface.surface_ptr == nullptr)
                throw sdl_exception("surface::CreateFromImage", IMG_GetError());

            IMG_Quit();

            return imageSurface;
        }

        ~surface()
        {
            if(surface_ptr != nullptr)
                SDL_FreeSurface(surface_ptr);
        }

        surface(const surface&) = delete;
        surface& operator=(const surface&) = delete;

        surface(surface&& other) noexcept
        {
            surface_ptr = other.surface_ptr;
            other.surface_ptr = nullptr;
        }

        surface& operator=(surface&& other) noexcept
        {
            if(surface_ptr != nullptr)
                SDL_FreeSurface(surface_ptr);

            surface_ptr = other.surface_ptr;
            other.surface_ptr = nullptr;

            return *this;
        }

        operator SDL_Surface*() const { return surface_ptr; }

        operator bool() const { return surface_ptr != nullptr; }
    };
}

/*
@startuml
namespace sdl {
    class surface {
        + {static} surface create_from_bitmap(const std::string& path)
        + {static} surface create_from_image(const std::string& path)
        + operator SDL_Surface*() const
        + operator bool() const
    }

    surface --> sdl_exception
    context .. surface : <<must exist>> <
}
@enduml
*/

#endif //SDL_CPP_SURFACE_H
