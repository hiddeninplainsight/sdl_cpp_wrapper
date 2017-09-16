#include "sdl_cpp/widgets/application.h"
#include "sdl_cpp/widgets/default_font.h"

namespace
{
    std::string
    executable_path_to_application_path(std::string const &executable_path)
    {
        return std::string{executable_path.cbegin(), executable_path.cbegin() +
                                                     executable_path.find_last_of(
                                                             '/')};
    }
}

namespace sdl
{
    namespace widgets
    {
        application::application(int argc, char** argv)
            : application_path{executable_path_to_application_path(argv[0])}
            , font{default_font, default_font_size, 14}
        {
        }

        void application::process_events()
        {
        }

        void application::process_graphics()
        {
        }

        void application::resize_font(int point_size)
        {
            font = ttf_font{default_font, default_font_size, point_size};
        }
    }
}
