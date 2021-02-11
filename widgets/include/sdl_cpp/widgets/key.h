#ifndef SDL_CPP_WIDGETS_KEY_H
#define SDL_CPP_WIDGETS_KEY_H

#include "sdl_cpp/key_state.h"
#include "application.h"

namespace sdl
{
	namespace widgets
	{
		class key
		{
		private:
			static application* current_application();

			key_state keyState;

		public:
			explicit key(SDL_Keycode keyCode);

			bool down() const;
			void clear_down();

			operator bool() const { return down(); }
		};
	}
}

#endif  // SDL_CPP_WIDGETS_KEY_H
