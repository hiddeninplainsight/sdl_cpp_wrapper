#ifndef SDL_CPP_EVENTS_H
#define SDL_CPP_EVENTS_H

#include <functional>

namespace sdl
{
    class quit_event_handler
    {
    public:
        virtual ~quit_event_handler() {}
        virtual void quit_event() = 0;
    };

    class events
    {
    private:
        quit_event_handler* quit_handler{nullptr};
    public:
        void poll() const;

        void set_quit_event_handler(quit_event_handler& handler)
        {
            quit_handler = &handler;
        }
    };
}

#endif // SDL_CPP_EVENTS_H