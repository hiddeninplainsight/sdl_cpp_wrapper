#ifndef SDL_CPP_WIDGETS_RESIZABLE_WIDGET_H
#define SDL_CPP_WIDGETS_RESIZABLE_WIDGET_H

#include "widget.h"

namespace sdl
{
    namespace widgets
    {
        class resizable_widget : public widget
        {
        public:
            resizable_widget(SDL_Point location)
                : widget{location}
            {
            }

            resizable_widget(int x, int y)
                : widget{x, y}
            {
            }

            void width(int value) { dimensions.w = value; }
            void height(int value) { dimensions.h = value; }
        };
    }
}

#endif //SDL_CPP_WIDGETS_RESIZABLE_WIDGET_H
