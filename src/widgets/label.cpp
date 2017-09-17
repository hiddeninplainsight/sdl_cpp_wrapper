#include "sdl_cpp/widgets/label.h"

namespace
{
    sdl::texture create_text_texture(sdl::renderer& renderer, sdl::fonts::ttf_font const& font, std::string const& text)
    {
        if(text.length())
        {
            return font.create_texture(renderer, text, {0x00, 0x00, 0x00, 0xFF});
        }
        return font.create_texture(renderer, " ", {0x00, 0x00, 0x00, 0xFF});
    }
}

namespace sdl
{
    namespace widgets
    {
        label::label(std::string const& text)
            : widget{0, 0}
            , displayed_text{text}
            , font{current_application()->font}
            , text_texture{create_text_texture(renderer, font, displayed_text)}
        {
            recalculate_size();
        }

        label::label(int x, int y, std::string const& text)
            : widget{x, y}
            , displayed_text{text}
            , font{current_application()->font}
            , text_texture{create_text_texture(renderer, font, displayed_text)}
        {
            recalculate_size();
        }

        std::string const& label::text() const
        {
            return displayed_text;
        }

        void label::text(std::string const& text)
        {
            displayed_text = text;
            refresh();
        }

        void label::draw()
        {
            if(is_visible)
            {
                renderer.copy(text_texture, x(), y());
            }
        }

        void label::refresh()
        {
            text_texture = create_text_texture(renderer, font, displayed_text);
            recalculate_size();
        }

        void label::recalculate_size()
        {
            auto text_size = text_texture.dimensions();
            dimensions.w = text_size.w;
            dimensions.h = text_size.h;
        }
    }
}
