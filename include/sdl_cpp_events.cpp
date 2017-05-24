#include "sdl_cpp_events.h"

#include <SDL2/SDL.h>

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
                default:
                    break;
            }
        }

    }
}
