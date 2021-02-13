#ifndef SDL_CPP_WRAPPER_WIDGET_CONTAINER_H
#define SDL_CPP_WRAPPER_WIDGET_CONTAINER_H

#include "widget.h"
#include <memory>
#include <vector>

namespace sdl
{
	namespace widgets2
	{
		class window;

		class widget_container : public widget
		{
			friend class window;
		public:
			using widget_ptr = std::shared_ptr<widget>;

		protected:
			static inline SDL_Rect& widget_screen_position(widget_ptr const& w)
			{
				return w->screen_position;
			}

			static inline SDL_Rect& widget_requested_position(widget_ptr const& w)
			{
				return w->requested_position;
			}

		protected:
			std::vector<widget_ptr> children;

			void set_renderer(renderer *r) override;
		public:
			virtual void add_widget(widget_ptr w);
			bool remove_widget(widget_ptr const& w);
		};
	}
}
#endif	// SDL_CPP_WRAPPER_WIDGET_CONTAINER_H
