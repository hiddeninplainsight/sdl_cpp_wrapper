#ifndef SDL_CPP_EVENT_KEYS_H
#define SDL_CPP_EVENT_KEYS_H

#include "events.h"

#include <SDL2/SDL.h>
#include <map>

namespace sdl
{
	class event_keys : public key_down_event_handler,
					   public key_up_event_handler
	{
	private:
		events& events_system;
		std::map<SDL_Keycode, key_down_event_handler*> key_down_handlers;
		std::map<SDL_Keycode, key_up_event_handler*> key_up_handlers;

	public:
		explicit event_keys(events& events_system);
		~event_keys() override;

		event_keys(event_keys const&) = delete;
		event_keys& operator=(event_keys const&) = delete;

		void add_key_down_event_handler(SDL_Keycode key,
										key_down_event_handler& handler);
		void remove_key_down_event_handler(SDL_Keycode key);

		void add_key_up_event_handler(SDL_Keycode key,
									  key_up_event_handler& handler);
		void remove_key_up_event_handler(SDL_Keycode key);

		virtual void key_down_event(SDL_Keycode key, Uint16 modifier) override;
		virtual void key_up_event(SDL_Keycode key, Uint16 modifier) override;
	};
}

// clang-format off
/*
@startuml
namespace sdl {
	class event_keys {
		+ event_keys(events& events_system)
		+ void add_key_down_event_handler(SDL_Keycode key, key_down_event_handler& handler)
		+ void remove_key_down_event_handler(SDL_Keycode key)
		+ void add_key_up_event_handler(SDL_Keycode key, key_up_event_handler& handler)
		+ void remove_key_up_event_handler(SDL_Keycode key)
	}

	key_down_event_handler <|.. event_keys
	key_up_event_handler <|.. event_keys

	key_down_event_handler "*" <--o "1" event_keys
	key_up_event_handler "*" <--o "1" event_keys
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_EVENT_KEYS_H
