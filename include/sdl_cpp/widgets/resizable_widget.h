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
            resizable_widget(int x, int y)
                : widget{x, y}
            {
            }

            virtual void width(int value) { dimensions.w = value; }
            virtual void height(int value) { dimensions.h = value; }
        };
    }
}

#endif //SDL_CPP_WIDGETS_RESIZABLE_WIDGET_H
