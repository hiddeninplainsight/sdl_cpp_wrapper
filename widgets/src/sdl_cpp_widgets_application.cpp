#include "sdl_cpp_widgets_application.h"

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
        {
        }

        void application::process_events()
        {
        }

        void application::process_graphics()
        {
        }
    }
}
