#ifndef SDL_CPP_POINT_TRANSFORMS_H
#define SDL_CPP_POINT_TRANSFORMS_H

#include <SDL2/SDL.h>
#include <cstddef>

namespace sdl
{
    double degrees_to_radians(double degrees);

    void rotate_points(SDL_Point const *source, SDL_Point *destination,
                       std::size_t numberOfPoints, double angle);

    void translate_points(SDL_Point const *source, SDL_Point *destination,
                          std::size_t numberOfPoints, int x, int y);

    void scale_points(SDL_Point const *source, SDL_Point *destination,
                      std::size_t numberOfPoints, double scale);
}

SDL_Point operator+(SDL_Point const& a, SDL_Point const & b);

#endif // SDL_CPP_POINT_TRANSFORMS_H
