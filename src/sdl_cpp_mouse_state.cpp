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
        (void)mouse_id;
        (void)button_state;
        (void)x_relative;
        (void)y_relative;
        x_coordinate = x;
        y_coordinate = y;
    }

    void mouse_state::mouse_button_pressed_event(Uint32 mouse_id, Uint8 button,
                                            Uint8 clicks, Sint32 x, Sint32 y)
    {
        (void)mouse_id;
        button_state_pressed[button].clicks = clicks;
        button_state_pressed[button].x = x;
        button_state_pressed[button].y = y;
    }

    void mouse_state::mouse_button_released_event(Uint32 mouse_id, Uint8 button,
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

    namespace
    {
        Uint8 const buttom_map[] =
        {
            SDL_BUTTON_LEFT,
            SDL_BUTTON_MIDDLE,
            SDL_BUTTON_RIGHT,
            SDL_BUTTON_X1,
            SDL_BUTTON_X2
        };
    }

    mouse_button_state mouse_state::button_press(mouse_button button, bool clear)
    {
        auto index = buttom_map[static_cast<size_t>(button)];
        auto button_state = button_state_pressed[index];

        if(clear)
        {
            button_state_pressed[index] = mouse_button_state{};
        }

        return button_state;
    }

    mouse_button_state mouse_state::button_release(mouse_button button, bool clear)
    {
        auto index = buttom_map[static_cast<size_t>(button)];
        auto button_state = button_state_released[index];

        if(clear)
        {
            button_state_released[index] = mouse_button_state{};
        }

        return button_state;
    }
}
