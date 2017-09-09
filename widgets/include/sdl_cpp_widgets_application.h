#ifndef SDL_CPP_WIDGETS_APPLICATION_H
#define SDL_CPP_WIDGETS_APPLICATION_H

#include "sdl_cpp.h"
#include "sdl_cpp_ttf_font_context.h"
#include "sdl_cpp_widgets_widget.h"

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
            sdl::ttf_font_context ttf_context;

        protected:
            sdl::events events;
            sdl::quit_event_bool quit{events};
            sdl::event_keys keys{events};

            sdl::event_mouse_dispatch mouse_events{events};

            std::string const application_path{};

        public:
            application(int argc, char** argv);
            virtual ~application() {}

            application(application const&) = delete;
            application& operator=(application const&) = delete;

        protected:
            virtual void process_events();
            virtual void process_graphics();
            virtual widget_creation_parameters widget_parameters() = 0;
        };
    }
}

#endif // SDL_CPP_WIDGETS_APPLICATION_H
