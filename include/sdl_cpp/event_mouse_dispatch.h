#ifndef SDL_CPP_EVENT_MOUSE_DISPATCH_H
#define SDL_CPP_EVENT_MOUSE_DISPATCH_H

#include "events.h"

#include <vector>

namespace sdl
{
    class event_mouse_dispatch : public mouse_motion_event_handler, public mouse_button_event_handler, public mouse_wheel_event_handler
    {
    private:
        events& events_system;
        std::vector<mouse_motion_event_handler*> motion_handlers;
        std::vector<mouse_button_event_handler*> button_handlers;
        std::vector<mouse_wheel_event_handler*> wheel_handlers;
    public:
        explicit event_mouse_dispatch(events& events_system);
        ~event_mouse_dispatch() override;

        event_mouse_dispatch(event_mouse_dispatch const&) = delete;
        event_mouse_dispatch& operator=(event_mouse_dispatch const&) = delete;

        virtual void mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y,
                                        Sint32 x_relative, Sint32 y_relative) override;
        virtual void mouse_button_pressed_event(Uint32 mouse_id, mouse_button button,
                                                Uint8 clicks, Sint32 x, Sint32 y) override;
        virtual void mouse_button_released_event(Uint32 mouse_id, mouse_button button,
                                                 Uint8 clicks, Sint32 x, Sint32 y) override;
        virtual void mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
                                       Uint32 direction) override;

        void add_mouse_motion_event_handler(mouse_motion_event_handler& handler);
        void remove_mouse_motion_event_handler(mouse_motion_event_handler& handler);
        void add_mouse_button_event_handler(mouse_button_event_handler& handler);
        void remove_mouse_button_event_handler(mouse_button_event_handler& handler);
        void add_mouse_wheel_event_handler(mouse_wheel_event_handler& handler);
        void remove_mouse_wheel_event_handler(mouse_wheel_event_handler& handler);
    };
}

/*
@startuml
namespace sdl {
    class event_mouse_dispatch {
        + explicit event_mouse_dispatch(events& events_system)
        + void add_mouse_motion_event_handler(mouse_motion_event_handler& handler)
        + void remove_mouse_motion_event_handler(mouse_motion_event_handler& handler)
        + void add_mouse_button_event_handler(mouse_button_event_handler& handler)
        + void remove_mouse_button_event_handler(mouse_button_event_handler& handler)
        + void add_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
        + void remove_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
    }

    mouse_motion_event_handler <|.. event_mouse_dispatch
    mouse_button_event_handler <|.. event_mouse_dispatch
    mouse_wheel_event_handler <|.. event_mouse_dispatch
}
@enduml
*/

#endif //SDL_CPP_EVENT_MOUSE_DISPATCH_H
