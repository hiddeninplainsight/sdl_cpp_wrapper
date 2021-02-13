#include "sdl_cpp/widgets2/widget.h"

namespace sdl
{
	namespace widgets2
	{
		void widget::set_renderer(renderer* r)
		{
			sdl_renderer = r;
		}

		void widget::screen_position_updated()
		{
		}

		void widget::draw()
		{
			sdl_renderer->set_draw_colour(0xFF, 0x00, 0x00);
			SDL_Point points[5] = {
				{ screen_position.x, screen_position.y },
				{ screen_position.x + screen_position.w, screen_position.y },
				{ screen_position.x + screen_position.w, screen_position.y + screen_position.h },
				{ screen_position.x, screen_position.y + screen_position.h },
				{ screen_position.x, screen_position.y }
			};
			sdl_renderer->draw_lines(points);
		}

		bool widget::x(int x)
		{
			requested_position.x = x;
			return true;
		}

		bool widget::y(int y)
		{
			requested_position.y = y;
			return true;
		}

		bool widget::width(int width)
		{
			requested_position.w = width;
			return true;
		}

		bool widget::height(int height)
		{
			requested_position.h = height;
			return true;
		}

		bool widget::position(int x, int y)
		{
			requested_position.x = x;
			requested_position.y = y;
			return true;
		}

		bool widget::position(SDL_Point position)
		{
			requested_position.x = position.x;
			requested_position.y = position.y;
			return true;
		}

		bool widget::dimensions(int width, int height)
		{
			requested_position.w = width;
			requested_position.h = height;
			return true;
		}
	}
}
