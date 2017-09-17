#include "sdl_cpp/collision_detection.h"

namespace sdl
{
    bool tri_point_collision(SDL_Point const &p0, SDL_Point const &p1, SDL_Point const &p2,
                             SDL_Point const &toCheck)
    {
        using U = decltype(SDL_Point::x);

        U const nx0 = p0.y - p1.y;
        U const ny0 = -(p0.x - p1.x);

        U const nx1 = p1.y - p2.y;
        U const ny1 = -(p1.x - p2.x);

        U const nx2 = p2.y - p0.y;
        U const ny2 = -(p2.x - p0.x);

        U const d0 = nx0 * (p0.x - toCheck.x) + ny0 * (p0.y - toCheck.y);
        U const d1 = nx1 * (p1.x - toCheck.x) + ny1 * (p1.y - toCheck.y);
        U const d2 = nx2 * (p2.x - toCheck.x) + ny2 * (p2.y - toCheck.y);

        U const zero {0};

        return ((d0 < zero) && (d1 < zero) && (d2 < zero));
    }

    bool circle_collision(SDL_Point const& circle_center, int radius, SDL_Point const& point)
    {
        using U = decltype(SDL_Point::x);

        U const dx = circle_center.x - point.x;
        U const dy = circle_center.y - point.y;

        return (radius * radius) > ((dx * dx) + (dy * dy));
    }
}
