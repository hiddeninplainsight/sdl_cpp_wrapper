#ifndef SDL_RENDERER_FORWARD_DECLARATION_H
#define SDL_RENDERER_FORWARD_DECLARATION_H

#include <SDL2/SDL.h>
#include "SDL_CPP_Exception.h"

namespace SDL
{
    class Texture;

    class Renderer
    {
    private:
        SDL_Renderer *renderer;
    public:
        Renderer(const Window& window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(renderer == nullptr)
                throw SDL_Exception("Renderer::Renderer", SDL_GetError());
        }

        ~Renderer() { SDL_DestroyRenderer(renderer); }

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;

        operator SDL_Renderer*() const { return renderer; }

        void Clear() const { SDL_RenderClear(renderer); }
        void Present() const { SDL_RenderPresent(renderer); }

        inline void Copy(const Texture& texture);
        inline void Copy(const Texture& texture, const SDL_Rect& destination);
        inline void Copy(const Texture& texture, int x, int y);
    };
}

#endif //SDL_RENDERER_FORWARD_DECLARATION_H
