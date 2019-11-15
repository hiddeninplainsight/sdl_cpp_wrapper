#ifndef SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
#define SDL_CPP_WIDGETS_WINDOW_APPLICATION_H

#include "../sdl_cpp.h"
#include "application.h"
#include "widget.h"

#include <string>

namespace sdl
{
	namespace widgets
	{
		class window_application final : public application
		{
		private:
			sdl::window window;
			sdl::renderer renderer;
			SDL_Color backgroundColour{ 0xFF, 0xFF, 0xFF, 0xFF };

		public:
			window_application(int argc, char** argv, std::string const& title,
							   int x, int y, int width, int height, bool vSync = true);

			window_application(std::string const& title,
							   int x, int y, int width, int height, bool vSync = true);

			void colour(SDL_Color colour);

			virtual sdl::renderer& get_renderer() override;
			virtual void draw() override;
		};
	}
}

#endif  // SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
