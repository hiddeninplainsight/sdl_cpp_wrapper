#include "sdl_cpp_event_key_state.h"

namespace sdl
{
    key_state::key_state(events& events_system, SDL_Keycode key)
        : events_system{events_system}
        , key{key}
    {
        add_to_events_system();
    }

    key_state::~key_state()
    {
        remove_from_events_system();
    }

    void key_state::add_to_events_system()
    {
        events_system.add_key_up_event_handler(key, *this);
        events_system.add_key_down_event_handler(key, *this);
    }

    void key_state::remove_from_events_system()
    {
        events_system.remove_key_up_event_handler(key);
        events_system.remove_key_down_event_handler(key);
    }

    void key_state::key_down_event(SDL_Keycode, Uint16)
    {
        down = true;
    }

    void key_state::key_up_event(SDL_Keycode, Uint16)
    {
        down = false;
    }

    void key_state::change_key(SDL_Keycode new_key)
    {
        remove_from_events_system();
        key = new_key;
        add_to_events_system();
    }
}
