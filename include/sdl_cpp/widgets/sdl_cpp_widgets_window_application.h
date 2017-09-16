#ifndef SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
#define SDL_CPP_WIDGETS_WINDOW_APPLICATION_H

#include "sdl_cpp_widgets_application.h"
#include "../sdl_cpp.h"
#include "sdl_cpp_widgets_widget.h"

#include <string>

namespace sdl
{
    namespace widgets
    {
        class window_application : public application
        {
        private:
            int application_exit_code{exit_code::ok};
            bool keep_running{true};

        protected:
            sdl::window window;
            sdl::renderer renderer{window};

        public:
            window_application(int argc, char** argv, std::string const& title, int x, int y, int width, int height);

            int run();

        protected:
            virtual void process_graphics() override;
            virtual widget_creation_parameters widget_parameters() override;
            void exit(int code);
        };
    }
}

#endif // SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
