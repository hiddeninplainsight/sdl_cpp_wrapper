#ifndef SDL_CPP_WIDGETS_LABEL_H
#define SDL_CPP_WIDGETS_LABEL_H

#include "sdl_cpp_widgets_widget.h"
#include "../ttf_font/sdl_cpp_ttf_font.h"

namespace sdl
{
    namespace widgets
    {
        class label : public widget
        {
        private:
            std::string displayed_text;
            sdl::ttf_font& font;

            sdl::texture text_texture;
        public:
            label(widget_creation_parameters const& parameters, std::string const& text = " ");

            std::string const& text() const;
            void text(std::string const& text);

            virtual void draw() override;
            virtual void refresh() override;
        };
    }
}

#endif //SDL_CPP_WIDGETS_LABEL_H
