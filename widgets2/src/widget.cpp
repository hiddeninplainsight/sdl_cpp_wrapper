#include "sdl_cpp/widgets2/widget.h"

namespace sdl
{
	namespace widgets2
	{
		void widget::set_renderer(renderer* r)
		{
			sdl_renderer = r;
		}

		void widget::draw()
		{
		}
	}
}
