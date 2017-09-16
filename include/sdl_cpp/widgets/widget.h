#ifndef SDL_CPP_WIDGETS_WIDGET_H
#define SDL_CPP_WIDGETS_WIDGET_H

#include "../sdl_cpp.h"
#include "sdl_cpp/ttf_font/ttf_font_context.h"
#include "sdl_cpp/ttf_font/ttf_font.h"

namespace sdl
{
    namespace widgets
    {
        struct widget_creation_parameters
        {
            sdl::renderer& renderer;
            sdl::ttf_font& font;
        };

        class widget
        {
        protected:
            sdl::renderer& renderer;

            SDL_Rect dimensions{0, 0, 20, 20};

        public:
            explicit widget(widget_creation_parameters const& parameters);
            virtual ~widget() {}

            SDL_Point location() const;
            void location(SDL_Point const& new_location);

            int x() const { return dimensions.x; }
            void x(int value) { dimensions.x = value; }

            int y() const { return dimensions.y; }
            void y(int value) { dimensions.y = value; }

            int width() const { return dimensions.w; }
            int height() const { return dimensions.h; }

            virtual void draw();
            virtual void refresh();
        };
    }
}

#endif //SDL_CPP_WIDGETS_WIDGET_H
