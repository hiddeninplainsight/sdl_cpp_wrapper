#ifndef SDL_CPP_TTF_FONT_H
#define SDL_CPP_TTF_FONT_H

#include "sdl_cpp/surface.h"
#include "sdl_cpp/texture.h"

#include <SDL2/SDL_ttf.h>
#include "sdl_cpp/sdl_exception.h"

#include <cstddef>
#include <string>

namespace sdl
{
	namespace fonts
	{
		struct ttf_font_text_size
		{
			int width;
			int height;
		};

		class ttf_font
		{
		private:
			TTF_Font* font;

		public:
			ttf_font(std::string const& file_path, int point_size);
			ttf_font(void const* memory, size_t size, int point_size);
			~ttf_font();
			ttf_font(ttf_font&& other) noexcept;
			ttf_font& operator=(ttf_font&& other) noexcept;

			ttf_font(const ttf_font&) = delete;
			ttf_font& operator=(const ttf_font&) = delete;

			ttf_font_text_size text_size(char const* text) const;
			ttf_font_text_size text_size(std::string const& text) const;

			surface create_surface(char const* text, SDL_Color colour) const;
			surface create_surface(std::string const& text,
								   SDL_Color colour) const;

			texture create_texture(const renderer& renderer, char const* text,
								   SDL_Color colour) const;
			texture create_texture(const renderer& renderer,
								   std::string const& text,
								   SDL_Color colour) const;
		};
	}
}

// clang-format off
/*
@startuml
namespace sdl {
	namespace fonts {
		class ttf_font_text_size << (S,#FF7700) struct >> {
			+ int width
			+ int height
		}

		class ttf_font {
			+ ttf_font(std::string const& file_path, int point_size)
			+ ttf_font(void* memory, size_t size, int point_size)
			+ ttf_font_text_size text_size(char const* text) const
			+ ttf_font_text_size text_size(std::string const& text) const
			+ surface create_surface(char const* text, SDL_Color colour) const
			+ surface create_surface(std::string const& text, SDL_Color colour) const
			+ texture create_texture(const renderer& renderer, char const* text, SDL_Color colour) const
			+ texture create_texture(const renderer& renderer, std::string const& text, SDL_Color colour) const
		}
	}

	sdl::fonts::ttf_font --> sdl::fonts::ttf_font_text_size
	sdl::fonts::ttf_font --> surface
	sdl::fonts::ttf_font --> texture

	sdl::fonts::ttf_font --> sdl_exception
	sdl::fonts::ttf_font_context .. sdl::fonts::ttf_font : <<must exist>> <
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_TTF_FONT_H
