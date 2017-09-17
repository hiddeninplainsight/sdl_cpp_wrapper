#include "sdl_cpp/widgets/window_application.h"

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

        sdl::renderer& window_application::get_renderer()
        {
            return renderer;
        }

        void window_application::draw()
        {
            renderer.set_draw_colour(0xAA, 0xAA, 0xAA);
            renderer.clear();

            for(auto w : widgets)
            {
                w->draw();
            }

            renderer.present();
        }

    }
}
