#ifndef SDL_CPP_SURFACE_H
#define SDL_CPP_SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

        static Surface CreateFromImage(const std::string& path)
        {
            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);
            if((initted & flags) != flags)
                throw SDL_Exception("Surface::CreateFromImage - IMG_Init", IMG_GetError());

            Surface imageSurface{IMG_Load(path.c_str())};
            if(imageSurface.surface == nullptr)
                throw SDL_Exception("Surface::CreateFromImage", IMG_GetError());

            IMG_Quit();

            return imageSurface;
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
