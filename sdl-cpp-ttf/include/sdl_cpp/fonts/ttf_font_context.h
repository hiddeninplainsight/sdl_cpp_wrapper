#ifndef SDL_CPP_TTF_FONT_CONTEXT_H
#define SDL_CPP_TTF_FONT_CONTEXT_H

#include <SDL2/SDL_ttf.h>
#include "sdl_cpp/sdl_exception.h"

namespace sdl
{
	namespace fonts
	{
		class ttf_font_context
		{
		public:
			ttf_font_context()
			{
				if (TTF_Init() == -1)
				{
					throw sdl_exception{
						"sdl_cpp_ttf_font_context::sdl_cpp_ttf_font_context",
						TTF_GetError()};
				}
			}

			~ttf_font_context() { TTF_Quit(); }
			ttf_font_context(const ttf_font_context&) = delete;
			ttf_font_context& operator=(const ttf_font_context&) = delete;
		};
	}
}

// clang-format off
/*
@startuml
namespace sdl {
	namespace fonts {
		class ttf_font_context

		note as ttf_font_context_note
		Initialises SDL TTF support when constructed,
		cleans up SDL TTF support when destroyed
		end note
		ttf_font_context_note .. ttf_font_context

		hide ttf_font_context methods
		hide ttf_font_context fields
	}

	sdl::fonts::ttf_font_context --> sdl_exception
	context .. sdl::fonts::ttf_font_context : <<must exist>> <

}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_TTF_FONT_CONTEXT_H
