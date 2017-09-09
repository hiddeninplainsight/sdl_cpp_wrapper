#ifndef SDL_RENDERER_FORWARD_DECLARATION_H
#define SDL_RENDERER_FORWARD_DECLARATION_H

#include <SDL2/SDL.h>
#include "sdl_cpp_exception.h"

namespace sdl
{
    class texture;
    class window;

    class renderer
    {
    private:
        SDL_Renderer *renderer_ptr;
    public:
        explicit renderer(const window& window);

        ~renderer() { SDL_DestroyRenderer(renderer_ptr); }

        renderer(const renderer&) = delete;
        renderer& operator=(const renderer&) = delete;

        operator SDL_Renderer*() const { return renderer_ptr; }

        void clear() const { SDL_RenderClear(renderer_ptr); }
        void present() const { SDL_RenderPresent(renderer_ptr); }

        inline void copy(const texture& texture);
        inline void copy(const texture& texture, const SDL_Rect& destination);
        inline void copy(const texture& texture, int x, int y);

        int draw_lines(SDL_Point const* points, int numberOfPoints)
        {
            return SDL_RenderDrawLines(renderer_ptr, points, numberOfPoints);
        }

        template<int number_of_points>
        int draw_lines(SDL_Point const (&points)[number_of_points])
        {
            return SDL_RenderDrawLines(renderer_ptr, points, number_of_points);
        }

        void set_draw_colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xFF)
        {
            SDL_SetRenderDrawColor(renderer_ptr, r, g, b, a);
        }
    };
}

/*
@startuml
namespace sdl {
    class renderer {
        + renderer(const window& window)
        + operator SDL_Renderer*() const
        + void clear() const
        + void present() const
        + void copy(const texture& texture)
        + void copy(const texture& texture, const SDL_Rect& destination)
        + void copy(const texture& texture, int x, int y)
        + int draw_lines(SDL_Point const* points, int numberOfPoints)
        + int draw_lines(SDL_Point const (&points)[number_of_points])
        + void set_draw_colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xFF)
    }

    renderer --> window
    renderer --> sdl_exception
    renderer --> texture
    context .. renderer : <<must exist>> <
}
@enduml
*/

#endif //SDL_RENDERER_FORWARD_DECLARATION_H
