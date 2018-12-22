#ifndef SDL_CPP_LERP_H
#define SDL_CPP_LERP_H

#include <SDL2/SDL.h>

namespace sdl
{
	int Lerp(int a, int b, float factor);
	SDL_Point Lerp(SDL_Point a, SDL_Point b, float factor);
}

#endif //SDL_CPP_LERP_H
