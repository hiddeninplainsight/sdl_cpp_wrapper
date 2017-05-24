#ifndef SDL_RENDERER_FORWARD_DECLARATION_H
#define SDL_RENDERER_FORWARD_DECLARATION_H

#include <SDL2/SDL.h>
#include "sdl_cpp_exception.h"

namespace sdl
{
    class texture;

    class renderer
    {
    private:
        SDL_Renderer *renderer_ptr;
    public:
        explicit renderer(const window& window)
        {
            renderer_ptr = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(renderer_ptr == nullptr)
                throw sdl_exception("renderer::renderer", SDL_GetError());
        }

        ~renderer() { SDL_DestroyRenderer(renderer_ptr); }

        renderer(const renderer&) = delete;
        renderer& operator=(const renderer&) = delete;

        operator SDL_Renderer*() const { return renderer_ptr; }

        void clear() const { SDL_RenderClear(renderer_ptr); }
        void present() const { SDL_RenderPresent(renderer_ptr); }

        inline void copy(const texture& texture);
        inline void copy(const texture& texture, const SDL_Rect& destination);
        inline void copy(const texture& texture, int x, int y);
    };
}

#endif //SDL_RENDERER_FORWARD_DECLARATION_H
