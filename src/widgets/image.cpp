#include "sdl_cpp/widgets/image.h"
#include "sdl_cpp/surface.h"

namespace sdl
{
    namespace widgets
    {
        image::image(std::string const& image_path)
            : widget{0, 0}
            , image_texture{current_application()->get_renderer(), sdl::surface::create_from_image(image_path)}
        {
            auto image_dimensions = image_texture.dimensions();
            dimensions.w = image_dimensions.w;
            dimensions.h = image_dimensions.h;
        }

        image::image(int x, int y, std::string const& image_path)
            : widget{x, y}
            , image_texture{current_application()->get_renderer(), sdl::surface::create_from_image(image_path)}
        {
            auto image_dimensions = image_texture.dimensions();
            dimensions.w = image_dimensions.w;
            dimensions.h = image_dimensions.h;
        }

        void image::draw()
        {
            if(is_visible)
            {
                renderer.copy(image_texture, dimensions.x, dimensions.y);
            }
        }
    }
}
