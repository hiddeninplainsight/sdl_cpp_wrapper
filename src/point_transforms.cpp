#include "sdl_cpp/point_transforms.h"
#include "sdl_cpp/maths.h"

#include <cmath>

namespace sdl
{
    void rotate_points(SDL_Point const *source, SDL_Point *destination,
                       std::size_t numberOfPoints, double angle)
    {
        double const radians = degrees_to_radians(angle);
        double const c = cos(radians);
        double const s = sin(radians);

        for(std::size_t i = 0; i < numberOfPoints; ++i)
        {
            using T = decltype(SDL_Point::x);

            auto const x = source[i].x;
            auto const y = source[i].y;

            destination[i].x = static_cast<T>((x * c) - (y * s));
            destination[i].y = static_cast<T>((x * s) + (y * c));
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

    void scale_points(SDL_Point const *source, SDL_Point *destination,
                      std::size_t numberOfPoints, double scale)
    {
        for(std::size_t i = 0; i < numberOfPoints; ++i)
        {
            destination[i].x = static_cast<int>(static_cast<double>(source[i].x) * scale);
            destination[i].y = static_cast<int>(static_cast<double>(source[i].y) * scale);
        }
    }
}

SDL_Point operator+(SDL_Point const& a, SDL_Point const & b)
{
    return SDL_Point{a.x + b.x, a.y + b.y};
}
