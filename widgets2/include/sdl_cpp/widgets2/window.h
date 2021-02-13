#ifndef SDL_CPP_WRAPPER_WINDOW_H
#define SDL_CPP_WRAPPER_WINDOW_H

#include "sdl_cpp/window.h"
#include "sdl_cpp/renderer.h"
#include "sdl_cpp/widgets2/widget_container.h"
#include "window_flags.h"
#include <memory>
#include <string>
#include <cstdint>
#include <SDL2/SDL.h>

namespace sdl
{
	namespace widgets2
	{
		class window
		{
		private:
			sdl::window sdl_window;
			sdl::renderer sdl_renderer;
			std::shared_ptr<widget_container> root_widget;

		public:
			uint32_t const id;

			window(std::string const& title, int x, int y, int width, int height, window_flags flags = window_flags::none);

			void set_root_widget(std::shared_ptr<widget_container> widget)
			{
				root_widget = widget;
			}

			void draw();
			void handle_event(SDL_Event const& event);
		};
	}
}

#endif	// SDL_CPP_WRAPPER_WINDOW_H
