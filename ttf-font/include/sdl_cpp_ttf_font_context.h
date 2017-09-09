#ifndef SDL_CPP_TTF_FONT_CONTEXT_H
#define SDL_CPP_TTF_FONT_CONTEXT_H

#include <SDL2/SDL_ttf.h>
#include <sdl_cpp_exception.h>

namespace sdl
{
    class ttf_font_context
    {
    public:
        ttf_font_context()
        {
            if(TTF_Init() == -1)
            {
                throw sdl_exception{"sdl_cpp_ttf_font_context::sdl_cpp_ttf_font_context", TTF_GetError()};
            }
        }

        ~ttf_font_context()
        {
            TTF_Quit();
        }

        ttf_font_context(const ttf_font_context&) = delete;
        ttf_font_context& operator=(const ttf_font_context&) = delete;
    };
}

#endif //SDL_CPP_TTF_FONT_CONTEXT_H
