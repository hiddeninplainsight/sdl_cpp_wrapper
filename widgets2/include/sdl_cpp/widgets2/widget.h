#ifndef SDL_CPP_WRAPPER_WIDGET_H
#define SDL_CPP_WRAPPER_WIDGET_H

#include "sdl_cpp/renderer.h"
#include <SDL2/SDL.h>

namespace sdl
{
	namespace widgets2
	{
		class widget_container;
		class window;

		class widget
		{
			friend class widget_container;
			friend class window;
		protected:
			renderer* sdl_renderer{nullptr};
			SDL_Rect requested_position{ 0, 0, 32, 32 };
			SDL_Rect screen_position{ 0, 0, 32, 32 };

			virtual void set_renderer(renderer* r);
			virtual void screen_position_updated();
		public:
			virtual ~widget() = default;
			virtual void draw();

			int actual_width() const { return screen_position.w; }
			int actual_height() const { return screen_position.h; }
			int x() const { return requested_position.x; }
			int y() const { return requested_position.y; }
			int width() const { return requested_position.w; }
			int height() const { return requested_position.h; }

			virtual bool x(int x);
			virtual bool y(int y);
			virtual bool width(int width);
			virtual bool height(int height);
			virtual bool position(int x, int y);
			virtual bool position(SDL_Point position);
			virtual bool dimensions(int width, int height);
		};
	}
}

#endif	// SDL_CPP_WRAPPER_WIDGET_H
