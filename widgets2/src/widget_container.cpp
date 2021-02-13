#include "sdl_cpp/widgets2/widget_container.h"
#include <algorithm>
#include <utility>

using namespace ::std;

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
			w->set_renderer(sdl_renderer);
			children.push_back(move(w));
		}

		bool widget_container::remove_widget(widget_ptr const& w)
		{
			auto const it = find(children.begin(), children.end(), w);
			if(it != children.end())
			{
				(*it)->set_renderer(nullptr);
				children.erase(it);
				return true;
			}
			return false;
		}
	}
}
