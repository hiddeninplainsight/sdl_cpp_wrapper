#ifndef SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
#define SDL_CPP_WIDGETS_WINDOW_APPLICATION_H

#include "application.h"
#include "../sdl_cpp.h"
#include "widget.h"

#include <string>

namespace sdl
{
    namespace widgets
    {
        class window_application final : public application
        {
        private:
            sdl::window window;
            sdl::renderer renderer{window};

        public:
            window_application(int argc, char** argv, std::string const& title, int x, int y, int width, int height);

            virtual sdl::renderer& get_renderer() override;
            virtual void draw() override;
        };
    }
}

#endif // SDL_CPP_WIDGETS_WINDOW_APPLICATION_H
