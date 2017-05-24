#ifndef SDL_CPP_EVENT_KEY_STATE_H
#define SDL_CPP_EVENT_KEY_STATE_H

#include "sdl_cpp_events.h"

namespace sdl
{
    class key_state : public key_down_event_handler, public key_up_event_handler
    {
    private:
        bool down{false};
        events& events_system;
        SDL_Keycode key;
    public:
        key_state(events& events_system, SDL_Keycode key);
        virtual ~key_state();
        key_state(key_state const&) = delete;
        key_state& operator=(key_state const&) = delete;

        virtual void key_down_event(SDL_Keycode key, Uint16 modifier) override;
        virtual void key_up_event(SDL_Keycode key, Uint16 modifier) override;

        operator bool() const { return down; }
    };
}

#endif // SDL_CPP_EVENT_KEY_STATE_H
