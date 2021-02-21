#include "sdl_cpp/widgets2/label.h"
#include <sdl_cpp/pixel_buffer_painter.h>
#include <freetype_cpp/library.h>
#include <freetype_cpp/face.h>
#include <PressStart2P_Regular_ttf.h>

using namespace std;

namespace
{
	class font_state
	{
	public:
		shared_ptr<freetype_cpp::library> freetype;
		shared_ptr<freetype_cpp::face> press_start_font;

		font_state()
		{
			freetype = freetype_cpp::library::initialise_instance();
			press_start_font = freetype_cpp::face::initialise_from_memory(freetype, PressStart2P_Regular_ttf, PressStart2P_Regular_ttf_len);
			press_start_font->set_font_size(16_points);
		}
	};

	font_state memory_fonts;


	class font_writer : public freetype_cpp::draw_glyph_callback
	{
	public:
		sdl::texture_pixel_buffer& pixels;
		int x_offset{0};
		int y_offset{0};

		explicit font_writer(sdl::texture_pixel_buffer& pixels)
			: pixels{pixels}
		{
		}

		void set_pixel(int x, int y)
		{
			if(x > 0 && x < pixels.size.width && y > 0 && y < pixels.size.height)
			{
				pixels.buffer[(y * pixels.size.width) + x] = 0xFFFFFFFF;
			}
		}

		void draw_glyph(FT_GlyphSlot const &glyph) override
		{
			auto p = glyph->bitmap.buffer;
			int top = y_offset;
			top -= glyph->bitmap_top;

			for(int y = 0; y < glyph->bitmap.rows; ++y)
			{
				for(int x = 0; x < glyph->bitmap.width; ++x)
				{
					if(*p)
					{
						int ox = x + glyph->bitmap_left + x_offset;
						int oy = y + top;
						set_pixel(ox, oy);
					}
					++p;
				}
			}
			x_offset += glyph->advance.x >> 6;
		}
	};
}

namespace sdl
{
	namespace widgets2
	{
		void label::update_texture()
		{
			sdl::texture_pixel_buffer pixels{texture_ptr.get()};
			pixels.clear(0x009900FF);

			auto painter =
					sdl::pixel_buffer_painter::from_texture_pixel_buffer(pixels);

			font_writer writer{pixels};
			auto line_height = memory_fonts.press_start_font->line_height() >> 6;
			writer.y_offset = line_height;

			memory_fonts.press_start_font->draw_glyph('H', writer);
			memory_fonts.press_start_font->draw_glyph('e', writer);
			memory_fonts.press_start_font->draw_glyph('l', writer);
			memory_fonts.press_start_font->draw_glyph('l', writer);
			memory_fonts.press_start_font->draw_glyph('g', writer);

			writer.x_offset = 0;
			writer.y_offset = (line_height + 0) * 2;

			memory_fonts.press_start_font->draw_glyph('W', writer);
			memory_fonts.press_start_font->draw_glyph('o', writer);
			memory_fonts.press_start_font->draw_glyph('r', writer);
			memory_fonts.press_start_font->draw_glyph('l', writer);
			memory_fonts.press_start_font->draw_glyph('D', writer);
/*
			int const radius = (requested_position.w / 2) - 10;
			int const x_and_y = requested_position.w / 2;

			painter.circle(x_and_y, x_and_y, radius, 0xFFFFFFFF, 1);
*/
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
