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

        void add_to_events_system();
        void remove_from_events_system();
    public:
        key_state(events& events_system, SDL_Keycode key);
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

#endif // SDL_CPP_EVENT_KEY_STATE_H
