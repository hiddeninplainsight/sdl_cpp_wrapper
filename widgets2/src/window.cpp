#include "sdl_cpp/widgets2/window.h"

#include <iostream>

namespace sdl
{
	namespace widgets2
	{
		namespace
		{
			constexpr inline SDL_WindowFlags operator|(SDL_WindowFlags lhs, SDL_WindowFlags rhs)
			{
				using T = std::underlying_type_t<SDL_WindowFlags>;
				return static_cast<SDL_WindowFlags>(static_cast<T>(lhs) | static_cast<T>(rhs));
			}

			constexpr inline SDL_WindowFlags& operator|=(SDL_WindowFlags& lhs, SDL_WindowFlags rhs)
			{
				lhs = lhs | rhs;
				return lhs;
			}

			inline SDL_WindowFlags window_flags_to_SDL_WindowFlags(window_flags flags)
			{
				SDL_WindowFlags sdl_flags = SDL_WINDOW_SHOWN;

				if((flags & window_flags::fixed_size) != window_flags::fixed_size)
				{
					sdl_flags |= SDL_WINDOW_RESIZABLE;
				}
				return sdl_flags;
			}
		} // namespace

		window::window(std::string const& title, int x, int y, int width, int height, window_flags flags)
			: sdl_window{title, x, y, width, height, window_flags_to_SDL_WindowFlags(flags)}
			, sdl_renderer{sdl_window}
			, id{sdl_window.ID()}
		{
		}

		void window::draw()
		{
			sdl_renderer.clear();
			sdl_renderer.set_draw_colour(0x00, 0x00, 0x00);

			if(root_widget)
			{
				root_widget->draw();
			}

			sdl_renderer.present();
		}

		void window::handle_event(SDL_Event const& event)
		{
			if(event.type == SDL_WINDOWEVENT)
			{
				std::cout << static_cast<uint32_t>(event.window.event) << " : "
						  << event.window.data1 << " x "
						  << event.window.data2 << std::endl;
			}
		}
	}
}
