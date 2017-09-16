#include "sdl_cpp/sdl_cpp_event_keys.h"

namespace sdl
{
    event_keys::event_keys(events& events_system)
        : events_system{events_system}
    {
        events_system.set_key_down_event_handler(*this);
        events_system.set_key_up_event_handler(*this);
    }

    event_keys::~event_keys()
    {
        events_system.clear_key_up_event_handler();
        events_system.clear_key_down_event_handler();
    }

    void event_keys::add_key_down_event_handler(SDL_Keycode key, key_down_event_handler& handler)
    {
        key_down_handlers[key] = &handler;
    }

    void event_keys::remove_key_down_event_handler(SDL_Keycode key)
    {
        key_down_handlers[key] = nullptr;
    }

    void event_keys::add_key_up_event_handler(SDL_Keycode key, key_up_event_handler& handler)
    {
        key_up_handlers[key] = &handler;
    }

    void event_keys::remove_key_up_event_handler(SDL_Keycode key)
    {
        key_up_handlers[key] = nullptr;
    }

    void event_keys::key_down_event(SDL_Keycode key, Uint16 modifier)
    {
        if(key_down_handlers.count(key) && key_down_handlers.at(key))
        {
            key_down_handlers.at(key)->key_down_event(key, modifier);
        }
    }

    void event_keys::key_up_event(SDL_Keycode key, Uint16 modifier)
    {
        if(key_up_handlers.count(key) && key_up_handlers.at(key))
        {
            key_up_handlers.at(key)->key_up_event(key, modifier);
        }
    }
}
