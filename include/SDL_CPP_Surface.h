#ifndef SDL_CPP_SURFACE_H
#define SDL_CPP_SURFACE_H

#include <SDL2/SDL.h>
#include <string>
#include "SDL_CPP_Exception.h"

namespace SDL
{
    class Surface
    {
    private:
        SDL_Surface *surface;
        Surface(SDL_Surface *surface)
                : surface{surface}
        {
        }
    public:
        static Surface CreateFromBitmap(const std::string& path)
        {
            Surface bitmapSurface{SDL_LoadBMP(path.c_str())};
            if(bitmapSurface.surface == nullptr)
                throw SDL_Exception("Surface::CreateFromBitmap", SDL_GetError());

            return bitmapSurface;
        }

        ~Surface()
        {
            if(surface != nullptr)
                SDL_FreeSurface(surface);
        }

        Surface(const Surface&) = delete;
        Surface& operator=(const Surface&) = delete;

        Surface(Surface&& other)
        {
            surface = other.surface;
            other.surface = nullptr;
        }

        Surface& operator=(Surface&& other)
        {
            if(surface != nullptr)
                SDL_FreeSurface(surface);

            surface = other.surface;
            other.surface = nullptr;

            return *this;
        }

        operator SDL_Surface*() const { return surface; }

        operator bool() const { return surface != nullptr; }
    };
}
#endif //SDL_CPP_SURFACE_H
