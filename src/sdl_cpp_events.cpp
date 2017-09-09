#include "sdl_cpp_events.h"

namespace sdl
{
    namespace
    {
        mouse_button SDL_BUTTON_to_mouse_button(Uint8 button)
        {
            switch(button)
            {
                case SDL_BUTTON_LEFT:
                    return mouse_button::left;
                case SDL_BUTTON_MIDDLE:
                    return mouse_button::middle;
                case SDL_BUTTON_RIGHT:
                    return mouse_button::right;
                case SDL_BUTTON_X1:
                    return mouse_button::x1;
                case SDL_BUTTON_X2:
                    return mouse_button::x2;
                default:
                    return mouse_button::unknown;
            }
        }
    }

    void events::poll() const
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    if(quit_handler)
                    {
                        quit_handler->quit_event();
                    }
                    break;

                case SDL_KEYDOWN:
                    if(event.key.repeat == 0 && key_down_handler)
                    {
                        key_down_handler->key_down_event(event.key.keysym.sym, event.key.keysym.mod);
                    }
                    break;

                case SDL_KEYUP:
                    if(event.key.repeat == 0 && key_up_handler)
                    {
                        key_up_handler->key_up_event(event.key.keysym.sym, event.key.keysym.mod);
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if(mouse_motion_handler)
                    {
                        mouse_motion_handler->mouse_motion_event(event.motion.which, event.motion.state, event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(mouse_button_handler)
                    {
                        mouse_button_handler->mouse_button_pressed_event(event.button.which, SDL_BUTTON_to_mouse_button(event.button.button), event.button.clicks, event.button.x, event.button.y);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(mouse_button_handler)
                    {
                        mouse_button_handler->mouse_button_released_event(event.button.which, SDL_BUTTON_to_mouse_button(event.button.button), event.button.clicks, event.button.x, event.button.y);
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    if(mouse_wheel_handler)
                    {
                        mouse_wheel_handler->mouse_wheel_event(event.wheel.which, event.wheel.x, event.wheel.y, event.wheel.direction);
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void events::set_quit_event_handler(quit_event_handler& handler)
    {
        quit_handler = &handler;
    }

    void events::clear_quit_event_handler()
    {
        quit_handler = nullptr;
    }

    void events::set_key_down_event_handler(key_down_event_handler& handler)
    {
        key_down_handler = &handler;
    }

    void events::clear_key_down_event_handler()
    {
        key_down_handler = nullptr;
    }

    void events::set_key_up_event_handler(key_up_event_handler& handler)
    {
        key_up_handler = &handler;
    }

    void events::clear_key_up_event_handler()
    {
        key_up_handler = nullptr;
    }

    void events::set_mouse_motion_event_handler(mouse_motion_event_handler& handler)
    {
        mouse_motion_handler = &handler;
    }

    void events::clear_mouse_motion_event_handler()
    {
        mouse_motion_handler = nullptr;
    }

    void events::set_mouse_button_event_handler(mouse_button_event_handler& handler)
    {
        mouse_button_handler = &handler;
    }

    void events::clear_mouse_button_event_handler()
    {
        mouse_button_handler = nullptr;
    }

    void events::set_mouse_wheel_event_handler(mouse_wheel_event_handler& handler)
    {
        mouse_wheel_handler = &handler;
    }

    void events::clear_mouse_wheel_event_handler()
    {
        mouse_wheel_handler = nullptr;
    }

}
