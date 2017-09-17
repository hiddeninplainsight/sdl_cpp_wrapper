#include "sdl_cpp/widgets/lines_no_storage.h"

namespace sdl
{
    namespace widgets
    {
        void lines_no_storage::colour(SDL_Color colour)
        {
            line_colour = colour;
        }

        void lines_no_storage::draw()
        {
            if(is_visible)
            {
                renderer.set_draw_colour(line_colour.r, line_colour.g,
                                         line_colour.b, line_colour.a);
                renderer.draw_lines(points, number_of_points);
            }
        }
    }
}
