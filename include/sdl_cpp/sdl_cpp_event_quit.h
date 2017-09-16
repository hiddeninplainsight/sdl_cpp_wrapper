#ifndef SDL_CPP_EVENT_QUIT_H
#define SDL_CPP_EVENT_QUIT_H

#include "sdl_cpp_events.h"

namespace sdl
{
    class quit_event_bool : public quit_event_handler
    {
    private:
        bool quit{false};
    public:
        quit_event_bool() = default;
        explicit quit_event_bool(events& events_system);

        virtual void quit_event() override;

        operator bool() const { return quit; }
    };
}

/*
@startuml
namespace sdl {
    class quit_event_bool {
        + quit_event_bool()
        + quit_event_bool(events& events_system)
        + operator bool() const
    }

    quit_event_handler <|.. quit_event_bool
}
@enduml
*/

#endif // SDL_CPP_EVENT_QUIT_H
