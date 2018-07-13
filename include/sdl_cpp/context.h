#ifndef SDL_CPP_CONTEXT_H
#define SDL_CPP_CONTEXT_H

#include <SDL2/SDL.h>
#include "sdl_exception.h"

namespace sdl
{
	class context final
	{
	public:
		context()
		{
			if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
				throw sdl_exception("context::context", SDL_GetError());
		}

		~context() { SDL_Quit(); }
		context(const context&) = delete;
		context& operator=(const context&) = delete;
	};
}

// clang-format off
/*
@startuml
namespace sdl {
	class context

	note as context_note
	Initialises SDL when constructed,
	cleans up SDL when destroyed
	end note
	context_note .. context

	hide context methods
	hide context fields
	context --> sdl_exception
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_CONTEXT_H
