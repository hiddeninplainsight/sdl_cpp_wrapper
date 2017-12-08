#include "sdl_cpp/widgets/application.h"
#include "sdl_cpp/widgets/default_font.h"
#include "sdl_cpp/widgets/widget.h"

#include <algorithm>

namespace
{
#ifdef WIN32
	char const path_seperator = '\\';
#else
	char const path_seperator = '/';
#endif

    std::string
    executable_path_to_application_path(std::string const &executable_path)
    {
        return std::string{executable_path.cbegin(), executable_path.cbegin() +
                                                     executable_path.find_last_of(
                                                             path_seperator) };
    }
}

namespace sdl
{
    namespace widgets
    {
        application* application::current{nullptr};

        application::application(int /*argc*/, char** argv)
            : application_path{executable_path_to_application_path(argv[0])}
            , font{default_font, default_font_size, 14}
        {
            current = this;
        }

        application::~application()
        {
            current = nullptr;
        }

        void application::add_widget(widget* w)
        {
            widgets.push_back(w);
        }

        void application::remove_widget(widget* w)
        {
            widgets.erase(std::remove(widgets.begin(), widgets.end(), w), widgets.end());
        }


        void application::resize_font(int point_size)
        {
            font = fonts::ttf_font{default_font, default_font_size, point_size};
        }
    }
}
