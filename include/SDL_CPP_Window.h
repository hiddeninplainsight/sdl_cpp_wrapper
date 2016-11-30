#ifndef SDL_CPP_WINDOW_H
#define SDL_CPP_WINDOW_H

#include <SDL.h>
#include <string>
#include "SDL_CPP_Exception.h"

namespace SDL
{
    class Window
    {
    private:
        SDL_Window *window;
    public:
        Window(const std::string& title, int x, int y, int width, int height)
        {
            window = SDL_CreateWindow(
                    title.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);

            if(window == nullptr)
                throw SDL_Exception("Window::Window", SDL_GetError());
        }

        ~Window() { SDL_DestroyWindow(window); }

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        operator SDL_Window*() const { return window; }
    };
}

#endif //SDL_CPP_WINDOW_H
