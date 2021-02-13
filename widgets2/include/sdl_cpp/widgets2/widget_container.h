#ifndef SDL_CPP_WRAPPER_WIDGET_CONTAINER_H
#define SDL_CPP_WRAPPER_WIDGET_CONTAINER_H

#include "widget.h"
#include <memory>
#include <vector>

namespace sdl
{
	namespace widgets2
	{
		class widget_container : public widget
		{
		public:
			using widget_ptr = std::shared_ptr<widget>;
		private:
			std::vector<widget_ptr> children;
		protected:
			void set_renderer(renderer *r) override;
		public:
			void add_widget(widget_ptr w);
			bool remove_widget(widget_ptr w);
		};
	}
}
#endif	// SDL_CPP_WRAPPER_WIDGET_CONTAINER_H
