#include "sdl_cpp/lerp.h"

namespace sdl
{
	int Lerp(int a, int b, float factor)
	{
		return static_cast<int>(a + ((b - a) * factor));
	}

	SDL_Point Lerp(SDL_Point a, SDL_Point b, float factor)
	{
		return SDL_Point
		{
			Lerp(a.x, b.x, factor),
			Lerp(a.y, b.y, factor)
		};
	}
}
