#include "sdl_cpp/widgets2/panel.h"
#include "sdl_cpp/renderer_clip_region.h"

namespace sdl
{
	namespace widgets2
	{
		void panel::update_childs_position(widget_ptr& child)
		{
			auto& requested = widget_container::widget_requested_position(child);
			auto& screen = widget_container::widget_screen_position(child);

			screen.x = screen_position.x + requested.x;
			screen.y = screen_position.y + requested.y;
			screen.w = requested.w;
			screen.h = requested.h;
		}

		void panel::screen_position_updated()
		{
			for(auto&& child : children)
			{
				update_childs_position(child);
			}
		}

		void panel::add_widget(widget_ptr w)
		{
			widget_container::add_widget(w);
			update_childs_position(w);
		}

		void panel::draw()
		{
			for(auto&& child : children)
			{
				//auto region = widget_container::widget_screen_position(child);
				//renderer_clip_region clip{sdl_renderer, region};

				child->draw();
			}
		}
	}
}
