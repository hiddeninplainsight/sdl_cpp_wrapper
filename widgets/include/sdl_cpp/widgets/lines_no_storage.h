#ifndef SDL_CPP_WIDGETS_LINES_NO_STORAGE_H
#define SDL_CPP_WIDGETS_LINES_NO_STORAGE_H

#include "widget.h"

#include <cstddef>

namespace sdl
{
	namespace widgets
	{
		class lines_no_storage : public widget
		{
		private:
			SDL_Point const* points;
			size_t number_of_points;

			SDL_Color line_colour;

		public:
			template <size_t N>
			explicit lines_no_storage(SDL_Point (&p)[N])
				: widget{0, 0}
				, points{p}
				, number_of_points{N}
				, line_colour{0x00, 0x00, 0x00, 0xFF}
			{
			}

			SDL_Color colour() const { return line_colour; }
			void colour(SDL_Color colour);

			void draw() override;
		};
	}
}

#endif  // SDL_CPP_WIDGETS_LINES_NO_STORAGE_H
