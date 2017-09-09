#include "sdl_cpp_mouse_state.h"

namespace sdl
{
    mouse_state::mouse_state(event_mouse_dispatch& mouse_events)
            : mouse_events{mouse_events}
    {
        mouse_events.add_mouse_button_event_handler(*this);
        mouse_events.add_mouse_motion_event_handler(*this);
        mouse_events.add_mouse_wheel_event_handler(*this);
    }

    mouse_state::~mouse_state()
    {
        mouse_events.remove_mouse_button_event_handler(*this);
        mouse_events.remove_mouse_motion_event_handler(*this);
        mouse_events.remove_mouse_wheel_event_handler(*this);
    }

    void mouse_state::mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y,
                       Sint32 x_relative, Sint32 y_relative)
    {
        (void)mouse_id;
        (void)button_state;
        (void)x_relative;
        (void)y_relative;
        x_coordinate = x;
        y_coordinate = y;
    }

    void mouse_state::mouse_button_pressed_event(Uint32 mouse_id, mouse_button button,
                                            Uint8 clicks, Sint32 x, Sint32 y)
    {
        (void)mouse_id;
        button_state_pressed[button].clicks = clicks;
        button_state_pressed[button].x = x;
        button_state_pressed[button].y = y;
    }

    void mouse_state::mouse_button_released_event(Uint32 mouse_id, mouse_button button,
                                             Uint8 clicks, Sint32 x, Sint32 y)
    {
        (void)mouse_id;
        button_state_released[button].clicks = clicks;
        button_state_released[button].x = x;
        button_state_released[button].y = y;
    }

    void mouse_state::mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
                                   Uint32 direction)
    {
        (void)mouse_id;
        (void)direction;
        x_wheel += x;
        y_wheel += y;
    }

    mouse_button_state mouse_state::button_press(mouse_button button, bool clear)
    {
        auto button_state = button_state_pressed[button];

        if(clear)
        {
            button_state_pressed[button] = mouse_button_state{};
        }

        return button_state;
    }

    mouse_button_state mouse_state::button_release(mouse_button button, bool clear)
    {
        auto button_state = button_state_released[button];

        if(clear)
        {
            button_state_released[button] = mouse_button_state{};
        }

        return button_state;
    }
}
