#include "sdl_cpp/widgets/widget.h"
#include "sdl_cpp/sdl_exception.h"

namespace sdl
{
	namespace widgets
	{
		application* widget::current_application()
		{
			if (application::current == nullptr)
			{
				throw sdl_exception{
					"widget::current_application",
					"Attempted to create widget with no active application"};
			}
			return application::current;
		}

		widget::widget(int x, int y)
			: renderer{current_application()->get_renderer()}
			, location{x, y}
			, dimensions{20, 20}
		{
			current_application()->add_widget(this);
		}

		widget::~widget() { current_application()->remove_widget(this); }
		void widget::show() { is_visible = true; }
		void widget::hide() { is_visible = false; }
		void widget::draw()
		{
			SDL_Point outline[5] = {
				{location.x, location.y},
				{location.x + dimensions.width, location.y},
				{location.x + dimensions.width, location.y + dimensions.height},
				{location.x, location.y + dimensions.height},
				{location.x, location.y},
			};

			renderer.set_draw_colour(0x00, 0x00, 0x00);
			renderer.draw_lines(outline);
		}

		void widget::refresh() {}
	}
}