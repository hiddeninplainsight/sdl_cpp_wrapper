#ifndef SDL_CPP_WRAPPER_APPLICATION_H
#define SDL_CPP_WRAPPER_APPLICATION_H

#include "sdl_cpp/sdl_cpp.h"
#include "sdl_cpp/widgets2/window.h"
#include "freetype_cpp/library.h"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

union SDL_Event;

namespace sdl
{
	namespace widgets2
	{
		class application
		{
		private:
			sdl::context context;
			std::shared_ptr<freetype_cpp::library> freetype;
			bool quit{false};
			std::vector<std::shared_ptr<window>> windows;
		public:
			application();
			application(application const&) = delete;
			application& operator=(application const&) = delete;

			template<class T = window, class... Args>
			std::shared_ptr<T> create_window(Args&&... args)
			{
				auto w = std::make_shared<T>(std::forward<Args>(args)...);
				windows.push_back(w);
				return w;
			}
		private:
			window* window_with_id(uint32_t id);
			bool pass_event_to_window(union SDL_Event& event);
		public:
			void poll_events();
			void draw_all_windows() const;
			void run();
			bool keep_running() const { return !quit; }
		};
	}
}

#endif	// SDL_CPP_WRAPPER_APPLICATION_H
