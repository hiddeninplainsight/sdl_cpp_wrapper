#include "sdl_cpp_mouse_state.h"

namespace sdl
{
    mouse_state::mouse_state(events &events_system)
            : events_system{events_system}
    {
        events_system.set_mouse_button_event_handler(*this);
        events_system.set_mouse_motion_event_handler(*this);
        events_system.set_mouse_wheel_event_handler(*this);
    }

    mouse_state::~mouse_state()
    {
        events_system.clear_mouse_button_event_handler();
        events_system.clear_mouse_motion_event_handler();
        events_system.clear_mouse_wheel_event_handler();
    }

    void mouse_state::mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y,
                       Sint32 x_relative, Sint32 y_relative)
    {
        x_coordinate = x;
        y_coordinate = y;
    }

    void mouse_state::mouse_button_pressed_event(Uint32 mouse_id, Uint8 button,
                                            Uint8 clicks, Sint32 x, Sint32 y)
    {

    }

    void mouse_state::mouse_button_released_event(Uint32 mouse_id, Uint8 button,
                                             Uint8 clicks, Sint32 x, Sint32 y)
    {

    }

    void mouse_state::mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
                                   Uint32 direction)
    {
        x_wheel += x;
        y_wheel += y;
    }
}