#include "sdl_cpp/widgets2/application.h"
#include <SDL2/SDL.h>
#include <algorithm>

using namespace ::std;

namespace sdl
{
	namespace widgets2
	{
		application::application()
			: freetype{freetype_cpp::library::initialise_instance()}
		{
		}

		window* application::window_with_id(uint32_t id)
		{
			auto is_valid_id = [id](shared_ptr<window>& w) -> bool
			{
				return id == w->id;
			};
			auto found_window = find_if(begin(windows), end(windows), is_valid_id);
			if(found_window != end(windows))
			{
				return found_window->get();
			}
			return nullptr;
		}

		bool application::pass_event_to_window(union SDL_Event& event)
		{
			window* w{nullptr};
			switch (event.type)
			{
			case SDL_WINDOWEVENT:
				w = window_with_id(event.window.windowID);
				break;
			case SDL_KEYDOWN:
				w = window_with_id(event.key.windowID);
				break;
			case SDL_KEYUP:
				w = window_with_id(event.key.windowID);
				break;
			case SDL_MOUSEMOTION:
				w = window_with_id(event.motion.windowID);
				break;
			case SDL_MOUSEBUTTONDOWN:
				w = window_with_id(event.button.windowID);
				break;
			case SDL_MOUSEBUTTONUP:
				w = window_with_id(event.button.windowID);
				break;
			case SDL_MOUSEWHEEL:
				w = window_with_id(event.wheel.windowID);
				break;
			default:
				break;
			}

			if(w)
			{
				w->handle_event(event);
				return true;
			}
			return false;
		}

		void application::poll_events()
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT)
				{
					quit = true;
				}
				else
				{
					pass_event_to_window(event);
				}
			}
		}

		void application::draw_all_windows() const
		{
			for(auto&& window : windows)
			{
				window->draw();
			}
		}

		void application::run()
		{
			while(keep_running())
			{
				poll_events();
				draw_all_windows();
			}
		}
	}
}
