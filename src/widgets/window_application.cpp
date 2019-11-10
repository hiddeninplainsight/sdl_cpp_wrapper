#include "sdl_cpp/widgets/window_application.h"

#include <iostream>

namespace sdl
{
	namespace widgets
	{
		window_application::window_application(int argc, char** argv,
											   std::string const& title, int x,
											   int y, int width, int height,
											   bool vSync)
			: application{argc, argv}
			, window{title, x, y, width, height}
			, renderer{window, vSync}
		{
		}

		void window_application::colour(SDL_Color colour)
		{
			backgroundColour = colour;
		}

		sdl::renderer& window_application::get_renderer() { return renderer; }
		void window_application::draw()
		{
			renderer.set_draw_colour(backgroundColour.r, backgroundColour.g, backgroundColour.b);
			renderer.clear();

			for (auto w : widgets)
			{
				w->draw();
			}

			renderer.present();
		}
	}
}
