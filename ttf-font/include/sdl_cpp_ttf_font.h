#ifndef SDL_CPP_TTF_FONT_H
#define SDL_CPP_TTF_FONT_H

#include <sdl_cpp_surface.h>
#include <sdl_cpp_texture.h>

#include <SDL2/SDL_ttf.h>
#include <sdl_cpp_exception.h>

#include <string>
#include <cstddef>

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

        ttf_font(void const* memory, size_t size, int point_size)
        {
            font = TTF_OpenFontRW(SDL_RWFromConstMem(memory, size), 1, point_size);
            if(font == nullptr)
            {
                throw sdl_exception{"ttf_font::ttf_font (from memory)", TTF_GetError()};
            }
        }

        ~ttf_font()
        {
            if(font != nullptr)
                TTF_CloseFont(font);
        }

        ttf_font(ttf_font&& other) noexcept
            : font{other.font}
        {
            other.font = nullptr;
        }

        ttf_font& operator=(ttf_font&& other) noexcept
        {
            if(font != nullptr)
                TTF_CloseFont(font);

            font = other.font;
            other.font = nullptr;

            return *this;
        }

        ttf_font(const ttf_font&) = delete;
        ttf_font& operator=(const ttf_font&) = delete;

        ttf_font_text_size text_size(char const* text) const
        {
            ttf_font_text_size size;
            if(!TTF_SizeText(font, text, &size.width, &size.height))
            {
                throw sdl_exception{"ttf_font::text_size", TTF_GetError()};
            }
        }

        ttf_font_text_size text_size(std::string const& text) const
        {
            return text_size(text.c_str());
        }

        surface create_surface(char const* text, SDL_Color colour) const
        {
            auto text_surface = TTF_RenderText_Solid(font, text, colour);

            if(text_surface == nullptr)
            {
                throw sdl_exception{"ttf_font::create_surface", TTF_GetError()};
            }

            return surface{text_surface};
        }

        surface create_surface(std::string const& text, SDL_Color colour) const
        {
            return create_surface(text.c_str(), colour);
        }

        texture create_texture(const renderer& renderer, char const* text, SDL_Color colour) const
        {
            return texture{renderer, create_surface(text, colour)};
        }

        texture create_texture(const renderer& renderer, std::string const& text, SDL_Color colour) const
        {
            return texture{renderer, create_surface(text.c_str(), colour)};
        }
    };
}

/*
@startuml
namespace sdl {
    class ttf_font_text_size << (S,#FF7700) struct >> {
        + int width
        + int height
    }

    class ttf_font {
        + ttf_font(std::string const& file_path, int point_size)
        + ttf_font(void* memory, size_t size, int point_size)
        + ttf_font_text_size text_size(char const* text) const
        + ttf_font_text_size text_size(std::string const& text) const
        + surface create_surface(char const* text, SDL_Color colour) const
        + surface create_surface(std::string const& text, SDL_Color colour) const
        + texture create_texture(const renderer& renderer, char const* text, SDL_Color colour) const
        + texture create_texture(const renderer& renderer, std::string const& text, SDL_Color colour) const
    }

    ttf_font --> ttf_font_text_size
    ttf_font --> surface
    ttf_font --> texture

    ttf_font --> sdl_exception
    ttf_font_context .. ttf_font : <<must exist>> <
}
@enduml
*/

#endif //SDL_CPP_TTF_FONT_H
