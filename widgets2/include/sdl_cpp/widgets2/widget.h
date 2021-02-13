#ifndef SDL_CPP_WRAPPER_WIDGET_H
#define SDL_CPP_WRAPPER_WIDGET_H

#include "sdl_cpp/renderer.h"

namespace sdl
{
	namespace widgets2
	{
		class widget_container;
		class window;

		class widget
		{
			friend widget_container;
			friend window;
		protected:
			renderer* sdl_renderer{nullptr};

			virtual void set_renderer(renderer* r);
		public:
			virtual ~widget() = default;
			virtual void draw();
		};
	}
}

#endif	// SDL_CPP_WRAPPER_WIDGET_H
