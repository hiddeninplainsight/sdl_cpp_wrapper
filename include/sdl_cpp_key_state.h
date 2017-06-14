#ifndef SDL_CPP_KEY_STATE_H
#define SDL_CPP_KEY_STATE_H

#include "sdl_cpp_event_keys.h"

namespace sdl
{
    class key_state : public key_down_event_handler, public key_up_event_handler
    {
    private:
        bool down{false};
        event_keys& events;
        SDL_Keycode key;

        void add_to_events_system();
        void remove_from_events_system();
    public:
        key_state(event_keys& events_system, SDL_Keycode key);
        virtual ~key_state();
        key_state(key_state const&) = delete;
        key_state& operator=(key_state const&) = delete;

        virtual void key_down_event(SDL_Keycode key, Uint16 modifier) override;
        virtual void key_up_event(SDL_Keycode key, Uint16 modifier) override;

        operator bool() const { return down; }

        void clear_down() { down = false; }
        void change_key(SDL_Keycode new_key);
    };
}

/*
@startuml
namespace sdl {
    class key_state {
        + key_state(event_keys& events_system, SDL_Keycode key)
        + operator bool() const
        + void clear_down()
        + void change_key(SDL_Keycode new_key)
    }

    key_down_event_handler <|.. key_state
    key_up_event_handler <|.. key_state
}
@enduml
*/

#endif // SDL_CPP_KEY_STATE_H
