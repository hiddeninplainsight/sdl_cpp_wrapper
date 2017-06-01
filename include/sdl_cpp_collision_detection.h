#ifndef SDL_CPP_COLLISION_DETECTION_H
#define SDL_CPP_COLLISION_DETECTION_H

#include <SDL2/SDL.h>

namespace sdl
{
    // checks if a point is inside a (clockwise defined) triangle
    template<typename T>
    bool tri_point_collision(T const& p0, T const& p1, T const& p2, T const& toCheck)
    {
        using U = decltype(T::x);

        U const nx0 = p0.y - p1.y;
        U const ny0 = -(p0.x - p1.x);

        U const nx1 = p1.y - p2.y;
        U const ny1 = -(p1.x - p2.x);

        U const nx2 = p2.y - p0.y;
        U const ny2 = -(p2.x - p0.x);

        U const d0 = nx0 * (p0.x - toCheck.x) + ny0 * (p0.y - toCheck.y);
        U const d1 = nx1 * (p1.x - toCheck.x) + ny1 * (p1.y - toCheck.y);
        U const d2 = nx2 * (p2.x - toCheck.x) + ny2 * (p2.y - toCheck.y);

        U const zero{0};

        return ((d0 < zero) && (d1 < zero) && (d2 < zero));
    }

    template<typename T>
    bool tri_point_collision(T const* points, T const& toCheck)
    {
        return tri_point_collision(points[0], points[1], points[2], toCheck);
    }
}

#endif // SDL_CPP_COLLISION_DETECTION_H
