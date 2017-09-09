#ifndef SDL_CPP_EVENTS_H
#define SDL_CPP_EVENTS_H

#include <SDL2/SDL.h>
#include <map>

namespace sdl
{
    class quit_event_handler;
    class key_down_event_handler;
    class key_up_event_handler;
    class mouse_motion_event_handler;
    class mouse_button_event_handler;
    class mouse_wheel_event_handler;

    class events
    {
    private:
        quit_event_handler* quit_handler{nullptr};
        key_down_event_handler* key_down_handler{nullptr};
        key_up_event_handler* key_up_handler{nullptr};
        mouse_motion_event_handler* mouse_motion_handler{nullptr};
        mouse_button_event_handler* mouse_button_handler{nullptr};
        mouse_wheel_event_handler* mouse_wheel_handler{nullptr};

    public:
        void poll() const;

        void set_quit_event_handler(quit_event_handler& handler);
        void clear_quit_event_handler();

        void set_key_down_event_handler(key_down_event_handler& handler);
        void clear_key_down_event_handler();

        void set_key_up_event_handler(key_up_event_handler& handler);
        void clear_key_up_event_handler();

        void set_mouse_motion_event_handler(mouse_motion_event_handler& handler);
        void clear_mouse_motion_event_handler();

        void set_mouse_button_event_handler(mouse_button_event_handler& handler);
        void clear_mouse_button_event_handler();

        void set_mouse_wheel_event_handler(mouse_wheel_event_handler& handler);
        void clear_mouse_wheel_event_handler();
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

    class mouse_motion_event_handler
    {
    public:
        virtual ~mouse_motion_event_handler() {}
        virtual void mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y,
                                        Sint32 x_relative, Sint32 y_relative) = 0;
    };

    class mouse_button_event_handler
    {
    public:
        virtual ~mouse_button_event_handler() {}
        virtual void mouse_button_pressed_event(Uint32 mouse_id, Uint8 button,
                                                Uint8 clicks, Sint32 x, Sint32 y) = 0;
        virtual void mouse_button_released_event(Uint32 mouse_id, Uint8 button,
                                                Uint8 clicks, Sint32 x, Sint32 y) = 0;
    };

    class mouse_wheel_event_handler
    {
    public:
        virtual ~mouse_wheel_event_handler() {}
        virtual void mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
                                       Uint32 direction) = 0;
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
        + void set_mouse_motion_event_handler(mouse_motion_event_handler& handler)
        + void clear_mouse_motion_event_handler()
        + void set_mouse_button_event_handler(mouse_button_event_handler& handler)
        + void clear_mouse_button_event_handler()
        + void set_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
        + void clear_mouse_wheel_event_handler()
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

    interface mouse_motion_event_handler {
        +{abstract} void mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y, Sint32 x_relative, Sint32 y_relative)
    }

    interface mouse_button_event_handler {
        +{abstract}  void mouse_button_pressed_event(Uint32 mouse_id, Uint8 button, Uint8 clicks, Sint32 x, Sint32 y)
        +{abstract}  void mouse_button_released_event(Uint32 mouse_id, Uint8 button, Uint8 clicks, Sint32 x, Sint32 y)
    }

    interface mouse_wheel_event_handler {
        +{abstract}  void mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y, Uint32 direction)
    }

    events o--> quit_event_handler
    events o--> key_down_event_handler
    events o--> key_up_event_handler
    events o--> mouse_motion_event_handler
    events o--> mouse_button_event_handler
    events o--> mouse_wheel_event_handler
    context .. events : <<must exist>> <
}
@enduml
*/

#endif // SDL_CPP_EVENTS_H