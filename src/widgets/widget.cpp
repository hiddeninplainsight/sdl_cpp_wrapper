#include "sdl_cpp/widgets/widget.h"
#include "sdl_cpp/sdl_exception.h"

namespace sdl
{
    namespace widgets
    {
        application* widget::current_application()
        {
            if(application::current == nullptr)
            {
                throw sdl_exception{"widget::current_application", "Attempted to create widget with no active application"};
            }
            return application::current;
        }

        widget::widget(int x, int y)
            : renderer{current_application()->get_renderer()}
            , dimensions{x, y, 20, 20}
        {
            current_application()->add_widget(this);
        }

        widget::~widget()
        {
            current_application()->remove_widget(this);
        }

        SDL_Point widget::location() const
        {
            return { dimensions.x, dimensions.y };
        }

        void widget::location(SDL_Point const& new_location)
        {
            dimensions.x = new_location.x;
            dimensions.y = new_location.y;
        }

        void widget::draw()
        {
            SDL_Point outline[5] =
            {
                { dimensions.x, dimensions.y },
                { dimensions.x + dimensions.w, dimensions.y },
                { dimensions.x + dimensions.w, dimensions.y + dimensions.h },
                { dimensions.x, dimensions.y + dimensions.h },
                { dimensions.x, dimensions.y },
            };

            renderer.set_draw_colour(0x00, 0x00, 0x00);
            renderer.draw_lines(outline);
        }

        void widget::refresh()
        {
        }
    }
}