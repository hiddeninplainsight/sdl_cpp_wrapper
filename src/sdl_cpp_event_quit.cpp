#include "sdl_cpp_event_quit.h"

namespace sdl
{

    quit_event_bool::quit_event_bool(events& events_system)
    {
        events_system.set_quit_event_handler(*this);
    }

    void quit_event_bool::quit_event()
    {
        quit = true;
    }
}