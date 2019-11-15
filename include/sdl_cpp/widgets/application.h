#ifndef SDL_CPP_WIDGETS_APPLICATION_H
#define SDL_CPP_WIDGETS_APPLICATION_H

#include <vector>
#include "../sdl_cpp.h"
#include "sdl_cpp/fonts/ttf_font.h"
#include "sdl_cpp/fonts/ttf_font_context.h"

namespace sdl
{
	namespace widgets
	{
		class widget;
		class key;

		class application
		{
			friend widget;
			friend key;

		private:
			sdl::context context;
			sdl::fonts::ttf_font_context ttf_context;

			static application* current;

		protected:
			std::vector<widget*> widgets;
			void add_widget(widget* w);
			void remove_widget(widget* w);

		public:
			sdl::events events;
			sdl::quit_event_bool quit{events};
			sdl::event_keys keys{events};

			sdl::event_mouse_dispatch mouse_events{events};

			std::string const application_path;

			sdl::fonts::ttf_font font;

		public:
			application(int argc, char** argv);
			application();
			virtual ~application();

			application(application const&) = delete;
			application& operator=(application const&) = delete;

			void resize_font(int point_size);

			virtual sdl::renderer& get_renderer() = 0;
			virtual void draw() = 0;
		};
	}
}

#endif  // SDL_CPP_WIDGETS_APPLICATION_H
