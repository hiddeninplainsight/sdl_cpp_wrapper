#include "sdl_cpp_point_transforms.h"

#include <cmath>

namespace sdl
{
    double degrees_to_radians(double degrees)
    {
        return (degrees * 2 * 3.142) / 360;
    }

    void rotate_points(SDL_Point const *source, SDL_Point *destination,
                       std::size_t numberOfPoints, double angle)
    {
        double const radians = degrees_to_radians(angle);
        double const c = cos(radians);
        double const s = sin(radians);

        for(std::size_t i = 0; i < numberOfPoints; ++i)
        {
            using T = decltype(SDL_Point::x);

            destination[i].x = static_cast<T>((source[i].x * c) - (source[i].y * s));
            destination[i].y = static_cast<T>((source[i].x * s) + (source[i].y * c));
        }
    }

    void translate_points(SDL_Point const *source, SDL_Point *destination,
                          std::size_t numberOfPoints, int x, int y)
    {
        for(std::size_t i = 0; i < numberOfPoints; ++i)
        {
            destination[i].x = source[i].x + x;
            destination[i].y = source[i].y + y;
        }
    }
}

SDL_Point operator+(SDL_Point const& a, SDL_Point const & b)
{
    return SDL_Point{a.x + b.x, a.y + b.y};
}
