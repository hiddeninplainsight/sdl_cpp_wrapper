#ifndef SDL_CPP_EVENTS_H
#define SDL_CPP_EVENTS_H

#include <SDL2/SDL.h>
#include <map>

namespace sdl
{
    class quit_event_handler;
    class key_down_event_handler;
    class key_up_event_handler;

    class events
    {
    private:
        quit_event_handler* quit_handler{nullptr};
        std::map<SDL_Keycode, key_down_event_handler*> key_down_handlers;
        std::map<SDL_Keycode, key_up_event_handler*> key_up_handlers;
    public:
        void poll() const;

        void set_quit_event_handler(quit_event_handler& handler);
        void clear_quit_event_handler();

        void add_key_down_event_handler(SDL_Keycode key, key_down_event_handler& handler);
        void remove_key_down_event_handler(SDL_Keycode key);

        void add_key_up_event_handler(SDL_Keycode key, key_up_event_handler& handler);
        void remove_key_up_event_handler(SDL_Keycode key);
    };

    class quit_event_handler
    {
    public:
        virtual ~quit_event_handler() {}
        virtual void quit_event() = 0;
    };

    class key_down_event_handler
    {
    public:
        virtual ~key_down_event_handler() {}
        virtual void key_down_event(SDL_Keycode key, Uint16 modifier) = 0;
    };

    class key_up_event_handler
    {
    public:
        virtual ~key_up_event_handler() {}
        virtual void key_up_event(SDL_Keycode key, Uint16 modifier) = 0;
    };
}

/*
@startuml
namespace sdl {
    class events {
        + void poll() const
        + void set_quit_event_handler(quit_event_handler& handler)
        + void clear_quit_event_handler()
        + void add_key_down_event_handler(SDL_Keycode key, key_down_event_handler& handler)
        + void remove_key_down_event_handler(SDL_Keycode key)
        + void add_key_up_event_handler(SDL_Keycode key, key_up_event_handler& handler)
        + void remove_key_up_event_handler(SDL_Keycode key)
    }

    interface quit_event_handler {
        +{abstract} void quit_event()
    }

    interface key_down_event_handler {
        +{abstract} void key_down_event(SDL_Keycode key, Uint16 modifier)
    }

    interface key_up_event_handler {
        +{abstract} void key_up_event(SDL_Keycode key, Uint16 modifier)
    }

    events o--> quit_event_handler
    events o--> key_down_event_handler
    events o--> key_up_event_handler
    context .. events : boo <
}
@enduml
*/

#endif // SDL_CPP_EVENTS_H