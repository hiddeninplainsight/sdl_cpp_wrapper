#include "sdl_cpp/widgets2/widget_container.h"
#include <algorithm>

namespace sdl
{
	namespace widgets2
	{
		void widget_container::set_renderer(renderer *r)
		{
			widget::set_renderer(r);
			for(auto&& child_widget : children)
			{
				child_widget->set_renderer(r);
			}
		}

		void widget_container::add_widget(widget_ptr w)
		{
			children.push_back(w);
		}

		bool widget_container::remove_widget(widget_ptr w)
		{
			auto const it = std::find(children.begin(), children.end(), w);
			if(it != children.end())
			{
				children.erase(it);
				return true;
			}
			return false;
		}
	}
}
