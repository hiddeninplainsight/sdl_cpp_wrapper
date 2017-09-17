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
            : displayed_text{text}
            , font{current_application()->font}
            , text_texture{create_text_texture(renderer, font, displayed_text)}
        {
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
            renderer.copy(text_texture, x(), y());
        }

        void label::refresh()
        {
            text_texture = create_text_texture(renderer, font, displayed_text);
        }
    }
}
