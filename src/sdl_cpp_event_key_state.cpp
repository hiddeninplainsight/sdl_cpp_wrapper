#include "sdl_cpp_event_key_state.h"

namespace sdl
{
    key_state::key_state(events& events_system, SDL_Keycode key)
        : events_system{events_system}
        , key{key}
    {
        events_system.add_key_up_event_handler(key, *this);
        events_system.add_key_down_event_handler(key, *this);
    }

    key_state::~key_state()
    {
        events_system.remove_key_up_event_handler(key);
        events_system.remove_key_down_event_handler(key);
    }

    void key_state::key_down_event(SDL_Keycode)
    {
        down = true;
    }

    void key_state::key_up_event(SDL_Keycode)
    {
        down = false;
    }

}
