#ifndef SDL_CPP_WRAPPER_PANEL_H
#define SDL_CPP_WRAPPER_PANEL_H

#include "widget_container.h"

namespace sdl
{
	namespace widgets2
	{
		class panel : public widget_container
		{
		protected:
			void update_childs_position(widget_ptr& child);
			void screen_position_updated() override;
		public:
			void add_widget(widget_ptr w) override;
			void draw() override;
		};
	}
}

#endif	// SDL_CPP_WRAPPER_PANEL_H
