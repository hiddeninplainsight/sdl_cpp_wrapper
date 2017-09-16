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
            explicit resizable_widget(widget_creation_parameters const& parameters)
                : widget(parameters)
            {
            }

            void width(int value) { dimensions.w = value; }
            void height(int value) { dimensions.h = value; }
        };
    }
}

#endif //SDL_CPP_WIDGETS_RESIZABLE_WIDGET_H