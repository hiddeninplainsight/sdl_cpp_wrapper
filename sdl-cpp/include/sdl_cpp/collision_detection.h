#ifndef SDL_CPP_COLLISION_DETECTION_H
#define SDL_CPP_COLLISION_DETECTION_H

#include <SDL2/SDL.h>

namespace sdl
{
	// checks if a point is inside a (clockwise defined) triangle
	bool tri_point_collision(SDL_Point const& p0, SDL_Point const& p1,
							 SDL_Point const& p2, SDL_Point const& toCheck);

	inline bool tri_point_collision(SDL_Point const* points,
									SDL_Point const& toCheck)
	{
		return tri_point_collision(points[0], points[1], points[2], toCheck);
	}

	bool circle_collision(SDL_Point const& circle_center, int radius,
						  SDL_Point const& point);
}

// clang-format off
/*
@startuml
namespace sdl {
	class "Collision detection functions" as collision_detection <<global>> {
		bool tri_point_collision(SDL_Point const& p0, SDL_Point const& p1, SDL_Point const& p2, SDL_Point const& toCheck)
		bool tri_point_collision(SDL_Point const* points, SDL_Point const& toCheck)
		bool circle_collision(SDL_Point const& circle_center, int radius, SDL_Point const& point)
	}
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_COLLISION_DETECTION_H
