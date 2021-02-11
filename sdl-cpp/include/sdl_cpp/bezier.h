#ifndef SDL_CPP_BEZIER_H
#define SDL_CPP_BEZIER_H

#include <SDL2/SDL.h>

namespace sdl
{
	struct BezierCurve
	{
		SDL_Point points[4];
	};

	void CalculateBezierCurvePoints(BezierCurve const& coordinates, SDL_Point* curvePoints, size_t numberOfCurvePoints);

	template<size_t numberOfCurvePoints>
	void CalculateBezierCurvePoints(BezierCurve const& coordinates, SDL_Point (&curvePoints)[numberOfCurvePoints])
	{
		CalculateBezierCurvePoints(coordinates, curvePoints, numberOfCurvePoints);
	}
}

#endif //SDL_CPP_BEZIER_H
