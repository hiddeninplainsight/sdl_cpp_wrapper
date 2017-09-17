#include "sdl_cpp/fonts/ttf_font.h"
namespace sdl
{
    namespace fonts
    {
        ttf_font::ttf_font(std::string const &file_path, int point_size)
        {
            font = TTF_OpenFont(file_path.c_str(), point_size);
            if (font == nullptr)
            {
                throw sdl_exception{"fonts::fonts", TTF_GetError()};
            }
        }

        ttf_font::ttf_font(void const *memory, size_t size, int point_size)
        {
            font = TTF_OpenFontRW(SDL_RWFromConstMem(memory, size), 1,
                                  point_size);
            if (font == nullptr)
            {
                throw sdl_exception{"fonts::fonts (from memory)",
                                    TTF_GetError()};
            }
        }

        ttf_font::~ttf_font()
        {
            if (font != nullptr)
                TTF_CloseFont(font);
        }

        ttf_font::ttf_font(ttf_font &&other) noexcept
                : font{other.font}
        {
            other.font = nullptr;
        }

        ttf_font &ttf_font::operator=(ttf_font &&other) noexcept
        {
            if (font != nullptr)
                TTF_CloseFont(font);

            font = other.font;
            other.font = nullptr;

            return *this;
        }

        ttf_font_text_size ttf_font::text_size(char const *text) const
        {
            ttf_font_text_size size;
            if (!TTF_SizeText(font, text, &size.width, &size.height))
            {
                throw sdl_exception{"fonts::text_size", TTF_GetError()};
            }

            return size;
        }

        ttf_font_text_size ttf_font::text_size(std::string const &text) const
        {
            return text_size(text.c_str());
        }

        surface
        ttf_font::create_surface(char const *text, SDL_Color colour) const
        {
            auto text_surface = TTF_RenderText_Solid(font, text, colour);

            if (text_surface == nullptr)
            {
                throw sdl_exception{"fonts::create_surface",
                                    TTF_GetError()};
            }

            return surface{text_surface};
        }

        surface
        ttf_font::create_surface(std::string const &text,
                                 SDL_Color colour) const
        {
            return create_surface(text.c_str(), colour);
        }

        texture
        ttf_font::create_texture(const renderer &renderer, char const *text,
                                 SDL_Color colour) const
        {
            return texture{renderer, create_surface(text, colour)};
        }

        texture
        ttf_font::create_texture(const renderer &renderer,
                                 std::string const &text,
                                 SDL_Color colour) const
        {
            return texture{renderer, create_surface(text.c_str(), colour)};
        }

    }
}
