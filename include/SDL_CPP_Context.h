#ifndef SDL_CPP_CONTEXT_H
#define SDL_CPP_CONTEXT_H

#include <SDL.h>
#include "SDL_CPP_Exception.h"

namespace SDL
{
    class Context
    {
    public:
        Context()
        {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
                throw SDL_Exception("SDLContext::SDLContext", SDL_GetError());
        }

        ~Context() { SDL_Quit(); }

        Context(const Context&) = delete;
        Context& operator=(const Context&) = delete;
    };
}

#endif //SDL_CPP_CONTEXT_H
