#include "sdl_cpp/maths.h"

namespace sdl
{
	double degrees_to_radians(double degrees)
	{
		return (degrees * tau) / 360.0;
	}
}