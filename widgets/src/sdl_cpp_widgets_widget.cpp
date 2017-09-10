#include "sdl_cpp_widgets_widget.h"

namespace sdl
{
    namespace widgets
    {
        widget::widget(widget_creation_parameters const& parameters)
            : renderer{parameters.renderer}
        {
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