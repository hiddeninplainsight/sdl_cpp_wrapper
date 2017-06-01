#ifndef SDL_CPP_COLLISION_DETECTION_H
#define SDL_CPP_COLLISION_DETECTION_H

#include <SDL2/SDL.h>

namespace sdl
{
    // checks if a point is inside a (clockwise defined) triangle
    bool tri_point_collision(SDL_Point const& p0, SDL_Point const& p1, SDL_Point const& p2,
                             SDL_Point const& toCheck);

    inline bool tri_point_collision(SDL_Point const* points, SDL_Point const& toCheck)
    {
        return tri_point_collision(points[0], points[1], points[2], toCheck);
    }
}

#endif // SDL_CPP_COLLISION_DETECTION_H
