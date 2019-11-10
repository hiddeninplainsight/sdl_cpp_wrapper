#ifndef SDL_CPP_WIDGETS_LABEL_H
#define SDL_CPP_WIDGETS_LABEL_H

#include "sdl_cpp/fonts/ttf_font.h"
#include "widget.h"

namespace sdl
{
	namespace widgets
	{
		class label : public widget
		{
		private:
			std::string displayed_text;
			sdl::fonts::ttf_font& font;
			SDL_Color textColour{ 0x00, 0x00, 0x00, 0xFF };

			sdl::texture text_texture;

		public:
			explicit label(std::string const& text = " ");
			label(int x, int y, std::string const& text = " ");

			std::string const& text() const;
			void text(std::string const& text);
			void colour(SDL_Color colour);
			void text_and_colour(std::string const& text, SDL_Color colour);

			virtual void draw() override;
			virtual void refresh() override;

		private:
			void recalculate_size();
		};
	}
}

#endif  // SDL_CPP_WIDGETS_LABEL_H
