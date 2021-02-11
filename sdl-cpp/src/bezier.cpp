#include "sdl_cpp/bezier.h"
#include "sdl_cpp/lerp.h"

namespace sdl
{

	/*

	 1----b----2
	 |   / \   |
	 |  /   \  |
	 | d--*--e |
	 |/       \|
	 a         c
	 |         |
	 |         |
	 |         |
	 0         3

	 */

	void
	CalculateBezierCurvePoints(BezierCurve const &coordinates, SDL_Point* curvePoints, size_t numberOfCurvePoints)
	{
		for(size_t i = 0; i < numberOfCurvePoints; ++i)
		{
			float const percentage = static_cast<float>(i) / static_cast<float>(numberOfCurvePoints - 1);
			SDL_Point a = Lerp(coordinates.points[0], coordinates.points[1], percentage);
			SDL_Point b = Lerp(coordinates.points[1], coordinates.points[2], percentage);
			SDL_Point c = Lerp(coordinates.points[2], coordinates.points[3], percentage);

			SDL_Point d = Lerp(a, b, percentage);
			SDL_Point e = Lerp(b, c, percentage);

			curvePoints[i] = Lerp(d, e, percentage);
		}
	}
}
