#ifndef SDL_CPP_WIDGETS_WIDGET_H
#define SDL_CPP_WIDGETS_WIDGET_H

#include "../sdl_cpp.h"
#include "sdl_cpp/fonts/ttf_font_context.h"
#include "sdl_cpp/fonts/ttf_font.h"
#include "application.h"

namespace sdl
{
    namespace widgets
    {
        struct widget_creation_parameters
        {
            sdl::renderer& renderer;
            sdl::fonts::ttf_font& font;
        };

        class widget
        {
        protected:
            sdl::renderer& renderer;

            SDL_Rect dimensions{0, 0, 20, 20};

            static application* current_application();
        public:
            widget(int x, int y);
            virtual ~widget();

            widget(widget const&) = delete;
            widget& operator=(widget const&) = delete;

            SDL_Point location() const;
            void location(SDL_Point const& new_location);

            int x() const { return dimensions.x; }
            virtual void x(int value) { dimensions.x = value; }

            int y() const { return dimensions.y; }
            virtual void y(int value) { dimensions.y = value; }

            int width() const { return dimensions.w; }
            int height() const { return dimensions.h; }

            virtual void draw();
            virtual void refresh();
        };
    }
}

#endif //SDL_CPP_WIDGETS_WIDGET_H
