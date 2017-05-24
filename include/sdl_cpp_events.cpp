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
                    if(event.key.repeat == 0)
                    {
                        auto sym = event.key.keysym.sym;
                        if(key_down_handlers.count(sym) && key_down_handlers.at(sym))
                        {
                            key_down_handlers.at(sym)->key_down_event(sym);
                        }
                    }
                    break;

                case SDL_KEYUP:
                    if(event.key.repeat == 0)
                    {
                        auto sym = event.key.keysym.sym;
                        if(key_up_handlers.count(sym) && key_up_handlers.at(sym))
                        {
                            key_up_handlers.at(sym)->key_up_event(sym);
                        }
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

    void events::add_key_down_event_handler(SDL_Keycode key, key_down_event_handler& handler)
    {
        key_down_handlers[key] = &handler;
    }

    void events::remove_key_down_event_handler(SDL_Keycode key)
    {
        key_down_handlers[key] = nullptr;
    }

    void events::add_key_up_event_handler(SDL_Keycode key, key_up_event_handler& handler)
    {
        key_up_handlers[key] = &handler;
    }

    void events::remove_key_up_event_handler(SDL_Keycode key)
    {
        key_up_handlers[key] = nullptr;
    }
}
