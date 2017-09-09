#ifndef SDL_CPP_TTF_FONT_H
#define SDL_CPP_TTF_FONT_H

#include <sdl_cpp_surface.h>
#include <sdl_cpp_texture.h>

#include <SDL2/SDL_ttf.h>
#include <sdl_cpp_exception.h>

#include <string>

namespace sdl
{
    struct ttf_font_text_size
    {
        int width;
        int height;
    };

    class ttf_font
    {
        TTF_Font* font;
    public:
        ttf_font(std::string const& file_path, int point_size)
        {
            font = TTF_OpenFont(file_path.c_str(), point_size);
            if(font == nullptr)
            {
                throw sdl_exception{"ttf_font::ttf_font", TTF_GetError()};
            }
        }

        ~ttf_font()
        {
            TTF_CloseFont(font);
        }

        ttf_font(const ttf_font&) = delete;
        ttf_font& operator=(const ttf_font&) = delete;

        ttf_font_text_size text_size(char const* text)
        {
            ttf_font_text_size size;
            if(!TTF_SizeText(font, text, &size.width, &size.height))
            {
                throw sdl_exception{"ttf_font::text_size", TTF_GetError()};
            }
        }

        ttf_font_text_size text_size(std::string const& text)
        {
            return text_size(text.c_str());
        }

        surface create_surface(char const* text, SDL_Color colour)
        {
            auto text_surface = TTF_RenderText_Solid(font, text, colour);

            if(text_surface == nullptr)
            {
                throw sdl_exception{"ttf_font::create_surface", TTF_GetError()};
            }

            return surface{text_surface};
        }

        surface create_surface(std::string const& text, SDL_Color colour)
        {
            return create_surface(text.c_str(), colour);
        }

        texture create_texture(const renderer& renderer, char const* text, SDL_Color colour)
        {
            return texture{renderer, create_surface(text, colour)};
        }

        texture create_texture(const renderer& renderer, std::string const& text, SDL_Color colour)
        {
            return texture{renderer, create_surface(text.c_str(), colour)};
        }
    };
}

#endif //SDL_CPP_TTF_FONT_H
