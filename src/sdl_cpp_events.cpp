#include "sdl_cpp_events.h"

namespace sdl
{
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
}
