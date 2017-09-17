#ifndef SDL_CPP_WIDGETS_IMAGE_H
#define SDL_CPP_WIDGETS_IMAGE_H

#include "widget.h"
#include "../texture.h"

#include <string>

namespace sdl
{
    namespace widgets
    {
        class image : public widget
        {
        private:
            sdl::texture image_texture;

        public:
            explicit image(std::string const& image_path);
            image(int x, int y, std::string const& image_path);

            void draw() override;
        };
    }
}

#endif //SDL_CPP_WIDGETS_IMAGE_H
