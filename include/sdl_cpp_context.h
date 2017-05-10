#ifndef SDL_CPP_CONTEXT_H
#define SDL_CPP_CONTEXT_H

#include <SDL2/SDL.h>
#include "sdl_cpp_exception.h"

namespace sdl
{
    class context
    {
    public:
        context()
        {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
                throw sdl_exception("context::context", SDL_GetError());
        }

        ~context() { SDL_Quit(); }

        context(const context&) = delete;
        context& operator=(const context&) = delete;
    };
}

#endif //SDL_CPP_CONTEXT_H
