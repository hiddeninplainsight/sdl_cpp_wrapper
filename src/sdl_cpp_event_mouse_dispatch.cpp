#include "sdl_cpp_event_mouse_dispatch.h"

#include <algorithm>

namespace sdl
{

    event_mouse_dispatch::event_mouse_dispatch(events& events_system)
        : events_system{events_system}
    {
        events_system.set_mouse_wheel_event_handler(*this);
        events_system.set_mouse_motion_event_handler(*this);
        events_system.set_mouse_button_event_handler(*this);
    }

    event_mouse_dispatch::~event_mouse_dispatch()
    {
        events_system.clear_mouse_wheel_event_handler();
        events_system.clear_mouse_motion_event_handler();
        events_system.clear_mouse_button_event_handler();
    }

    void event_mouse_dispatch::mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y,
                            Sint32 x_relative, Sint32 y_relative)
    {
        for(auto handler : motion_handlers)
        {
            handler->mouse_motion_event(mouse_id, button_state, x, y, x_relative, y_relative);
        }
    }

    void event_mouse_dispatch::mouse_button_pressed_event(Uint32 mouse_id, mouse_button button,
                                            Uint8 clicks, Sint32 x, Sint32 y)
    {
        for(auto handler : button_handlers)
        {
            handler->mouse_button_pressed_event(mouse_id, button, clicks, x, y);
        }
    }

    void event_mouse_dispatch::mouse_button_released_event(Uint32 mouse_id, mouse_button button,
                                             Uint8 clicks, Sint32 x, Sint32 y)
    {
        for(auto handler : button_handlers)
        {
            handler->mouse_button_released_event(mouse_id, button, clicks, x, y);
        }
    }

    void event_mouse_dispatch::mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
                                   Uint32 direction)
    {
        for(auto handler : wheel_handlers)
        {
            handler->mouse_wheel_event(mouse_id, x, y, direction);
        }
    }

    void event_mouse_dispatch::add_mouse_motion_event_handler(mouse_motion_event_handler& handler)
    {
        motion_handlers.push_back(&handler);
    }

    void event_mouse_dispatch::remove_mouse_motion_event_handler(mouse_motion_event_handler& handler)
    {
        motion_handlers.erase(std::remove(motion_handlers.begin(), motion_handlers.end(), &handler), motion_handlers.end());
    }

    void event_mouse_dispatch::add_mouse_button_event_handler(mouse_button_event_handler& handler)
    {
        button_handlers.push_back(&handler);
    }

    void event_mouse_dispatch::remove_mouse_button_event_handler(mouse_button_event_handler& handler)
    {
        button_handlers.erase(std::remove(button_handlers.begin(), button_handlers.end(), &handler), button_handlers.end());
    }

    void event_mouse_dispatch::add_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
    {
        wheel_handlers.push_back(&handler);
    }

    void event_mouse_dispatch::remove_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
    {
        wheel_handlers.erase(std::remove(wheel_handlers.begin(), wheel_handlers.end(), &handler), wheel_handlers.end());
    }
}
