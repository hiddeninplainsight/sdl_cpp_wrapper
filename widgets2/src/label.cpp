#include "sdl_cpp/widgets2/label.h"
#include "sdl_cpp/widgets2/font_writer.h"
#include <freetype_cpp/library.h>
#include <freetype_cpp/face.h>
#include <PressStart2P_Regular_ttf.h>
#include <utility>

using namespace std;

namespace
{
	class font_state
	{
	private:
		int press_start_font_line_height_internal;

	public:
		shared_ptr<freetype_cpp::library> freetype;
		shared_ptr<freetype_cpp::face> press_start_font;
		int const& press_start_font_line_height{press_start_font_line_height_internal};

		font_state()
			: freetype{freetype_cpp::library::initialise_instance()}
			, press_start_font{freetype_cpp::face::initialise_from_memory(freetype, PressStart2P_Regular_ttf, PressStart2P_Regular_ttf_len)}
		{
			press_start_font->set_font_size(10_points);

			press_start_font_line_height_internal = press_start_font->line_height() >> 6;
		}
	};

	font_state memory_fonts;
}

namespace sdl
{
	namespace widgets2
	{
		label::label(std::string text)
			: label_text{move(text)}
		{
		}

		void label::update_texture()
		{
			sdl::texture_pixel_buffer pixels{texture_ptr.get()};
			pixels.clear(0x222222FF);

			font_writer writer{pixels};
			auto line_height = memory_fonts.press_start_font_line_height;
			writer.y = (requested_position.h / 2) + (line_height / 2);

			for(auto&& c : label_text)
			{
				memory_fonts.press_start_font->draw_glyph(c, writer);
			}
			pixels.update_texture();
		}

		void label::recreate_texture()
		{
			if (sdl_renderer)
			{
				texture_ptr = make_unique<sdl::texture>(
						*sdl_renderer, requested_position.w, requested_position.h);
				update_texture();
			}
		}

		void label::set_renderer(sdl::renderer *r)
		{
			texture_ptr = nullptr;
			widget::set_renderer(r);
			recreate_texture();
		}

		void label::draw()
		{
			sdl_renderer->copy(*texture_ptr, screen_position);
		}

		bool label::dimensions(int width, int height)
		{
			if (!widget::dimensions(width, height))
				return false;
			recreate_texture();
			return true;
		}
	}
}
