#ifndef SDL_CPP_MATHS_H
#define SDL_CPP_MATHS_H

namespace sdl
{
	double const pi = 3.14159265359;
	double const tau = 2.0 * pi;

	double degrees_to_radians(double degrees);
}

// clang-format off
/*
@startuml
namespace sdl {
	class "Maths functions" as maths <<global>> {
		double const pi
		double const tau
		double degrees_to_radians(double degrees)
	}

	show maths fields
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_MATHS_H
