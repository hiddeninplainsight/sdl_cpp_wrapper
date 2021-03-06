#include "sdl_cpp/widgets/label.h"

namespace
{
	sdl::texture create_text_texture(sdl::renderer& renderer,
									 sdl::fonts::ttf_font const& font,
									 SDL_Color& colour,
									 std::string const& text)
	{
		if (text.length())
		{
			return font.create_texture(renderer, text, colour);
		}
		return font.create_texture(renderer, " ", colour);
	}
}

namespace sdl
{
	namespace widgets
	{
		label::label(std::string const& text)
			: widget{0, 0}
			, displayed_text{text}
			, font{current_application()->font}
			, text_texture{create_text_texture(renderer, font, textColour, displayed_text)}
		{
			recalculate_size();
		}

		label::label(int x, int y, std::string const& text)
			: widget{x, y}
			, displayed_text{text}
			, font{current_application()->font}
			, text_texture{create_text_texture(renderer, font, textColour, displayed_text)}
		{
			recalculate_size();
		}

		std::string const& label::text() const { return displayed_text; }
		void label::text(std::string const& text)
		{
			displayed_text = text;
			refresh();
		}

		void label::colour(SDL_Color colour)
		{
			textColour = colour;
			refresh();
		}

		void label::text_and_colour(std::string const& text, SDL_Color colour)
		{
			textColour = colour;
			displayed_text = text;
			refresh();
		}

		void label::draw()
		{
			if (is_visible)
			{
				renderer.copy(text_texture, location.x, location.y);
			}
		}

		void label::refresh()
		{
			text_texture = create_text_texture(renderer, font, textColour, displayed_text);
			recalculate_size();
		}

		void label::recalculate_size()
		{
			auto text_size = text_texture.dimensions();
			dimensions.width = text_size.w;
			dimensions.height = text_size.h;
		}
	}
}
