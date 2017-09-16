#include "sdl_cpp/widgets/sdl_cpp_widgets_window_application.h"

#include <iostream>

namespace sdl
{
    namespace widgets
    {
        window_application::window_application(int argc, char** argv,
                                               std::string const& title,
                                               int x, int y,
                                               int width, int height)
            : application{argc, argv}
            , window{title, x, y, width, height}
        {
        }

        int window_application::run()
        {
            try
            {
                while(!quit && keep_running)
                {
                    events.poll();

                    process_events();
                    process_graphics();

                    renderer.present();
                }
            }
            catch(sdl::sdl_exception const& error)
            {
                std::cerr << "SDL Exception : " << error.what() << std::endl;
                return exit_code::sdl_exception;
            }

            return application_exit_code;
        }

        void window_application::process_graphics()
        {
            renderer.set_draw_colour(0xAA, 0xAA, 0xAA);
            renderer.clear();
        }

        widget_creation_parameters window_application::widget_parameters()
        {
            return {renderer, font};
        }

        void window_application::exit(int code)
        {
            application_exit_code = code;
            keep_running = false;
        }
    }
}
