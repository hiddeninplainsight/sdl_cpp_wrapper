#ifndef SDL_CPP_WINDOW_H
#define SDL_CPP_WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include "sdl_exception.h"

namespace sdl
{
	class window
	{
	private:
		SDL_Window* window_ptr;

	public:
		window(const std::string& title, int x, int y, int width, int height,
			   SDL_WindowFlags flags = SDL_WINDOW_SHOWN)
		{
			window_ptr = SDL_CreateWindow(title.c_str(), x, y, width, height,
										  flags);

			if (window_ptr == nullptr)
				throw sdl_exception("window::window", SDL_GetError());
		}

		~window() { SDL_DestroyWindow(window_ptr); }
		window(const window&) = delete;
		window& operator=(const window&) = delete;

		operator SDL_Window*() const { return window_ptr; }

		Uint32 ID() const { return SDL_GetWindowID(window_ptr); }
	};
}

// clang-format off
/*
@startuml
namespace sdl {
	class window {
		+ window(const std::string& title, int x, int y, int width, int height)
		+ operator SDL_Window*() const
	}

	window --> sdl_exception
	context .. window : <<must exist>> <
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_WINDOW_H
