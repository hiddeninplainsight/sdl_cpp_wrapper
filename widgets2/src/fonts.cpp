#include "sdl_cpp/widgets2/fonts.h"

namespace sdl
{
	namespace widgets2
	{
		namespace internal
		{
			font_state::font_state()
					: freetype{freetype_cpp::library::initialise_instance()}, press_start_font{
					freetype_cpp::face::initialise_from_memory(freetype, PressStart2P_Regular_ttf,
															   PressStart2P_Regular_ttf_len)}
			{
				press_start_font->set_font_size(10_points);

				press_start_font_line_height_internal = press_start_font->line_height() >> 6;
			}
		}

		internal::font_state &fonts()
		{
			static internal::font_state state;

			return state;
		}
	}
}

