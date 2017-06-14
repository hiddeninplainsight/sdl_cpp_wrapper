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
        key_down_event_handler* key_down_handler{nullptr};
        key_up_event_handler* key_up_handler{nullptr};
    public:
        void poll() const;

        void set_quit_event_handler(quit_event_handler& handler);
        void clear_quit_event_handler();

        void set_key_down_event_handler(key_down_event_handler& handler);
        void clear_key_down_event_handler();

        void set_key_up_event_handler(key_up_event_handler& handler);
        void clear_key_up_event_handler();
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
        + void set_key_down_event_handler(key_down_event_handler& handler)
        + void clear_key_down_event_handler()
        + void set_key_up_event_handler(key_up_event_handler& handler)
        + void clear_key_up_event_handler()
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
    context .. events : <<must exist>> <
}
@enduml
*/

#endif // SDL_CPP_EVENTS_H