#ifndef SDL_CPP_WIDGETS_WIDGET_H
#define SDL_CPP_WIDGETS_WIDGET_H

#include "../sdl_cpp.h"
#include "application.h"
#include "sdl_cpp/fonts/ttf_font.h"
#include "sdl_cpp/fonts/ttf_font_context.h"

namespace sdl
{
	namespace widgets
	{
		struct widget_creation_parameters
		{
			sdl::renderer& renderer;
			sdl::fonts::ttf_font& font;
		};

		struct widget_dimensions
		{
			int width;
			int height;
		};

		class widget
		{
		protected:
			sdl::renderer& renderer;

		public:
			SDL_Point location{0, 0};

		protected:
			widget_dimensions dimensions{20, 20};
			bool is_visible{true};

			static application* current_application();

		public:
			widget(int x, int y);
			virtual ~widget();

			widget(widget const&) = delete;
			widget& operator=(widget const&) = delete;

			int width() const { return dimensions.width; }
			int height() const { return dimensions.height; }
			bool visible() const { return is_visible; }
			virtual void show();
			virtual void hide();

			virtual void draw();
			virtual void refresh();
		};
	}
}

#endif  // SDL_CPP_WIDGETS_WIDGET_H
