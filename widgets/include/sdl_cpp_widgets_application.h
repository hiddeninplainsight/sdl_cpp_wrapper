#ifndef SDL_CPP_WIDGETS_APPLICATION_H
#define SDL_CPP_WIDGETS_APPLICATION_H

#include "sdl_cpp.h"

namespace sdl
{
    namespace widgets
    {
        struct exit_code
        {
            enum
            {
                ok,
                sdl_exception,
                user_defined
            };
        };

        class application
        {
        private:
            sdl::context context;

        protected:
            sdl::events events;
            sdl::quit_event_bool quit{events};
            sdl::event_keys keys{events};

            sdl::event_mouse_dispatch mouse_events{events};
            sdl::mouse_state mouse{mouse_events};

            std::string const application_path{};

        public:
            application(int argc, char** argv);
            virtual ~application() {}

            application(application const&) = delete;
            application& operator=(application const&) = delete;

        protected:
            virtual void process_events();
            virtual void process_graphics();
        };
    }
}

#endif // SDL_CPP_WIDGETS_APPLICATION_H
