#ifndef SDL_CPP_WRAPPER_FONTS_H
#define SDL_CPP_WRAPPER_FONTS_H

#include <freetype_cpp/library.h>
#include <freetype_cpp/face.h>
#include <PressStart2P_Regular_ttf.h>

namespace sdl
{
	namespace widgets2
	{
		namespace internal
		{
			class font_state;
		}

		internal::font_state& fonts();

		namespace internal
		{
			class font_state
			{
			private:
				int press_start_font_line_height_internal;

			public:
				std::shared_ptr<freetype_cpp::library> freetype;
				std::shared_ptr<freetype_cpp::face> press_start_font;
				int const &press_start_font_line_height{press_start_font_line_height_internal};

			protected:
				font_state();
			public:
				font_state(font_state const&) = delete;
				font_state& operator=(font_state const&) = delete;
				~font_state() = default;

				friend font_state& sdl::widgets2::fonts();
			};
		}
	}
}

#endif //SDL_CPP_WRAPPER_FONTS_H
