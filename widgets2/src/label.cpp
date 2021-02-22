#include "sdl_cpp/widgets2/label.h"
#include "sdl_cpp/widgets2/font_writer.h"
#include "sdl_cpp/widgets2/fonts.h"
#include <utility>

using namespace std;

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

			auto line_height = fonts().press_start_font_line_height;
			writer.y = (requested_position.h / 2) + (line_height / 2);

			auto& font = fonts().press_start_font;
			for(auto&& c : label_text)
			{
				font->draw_glyph(c, writer);
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
