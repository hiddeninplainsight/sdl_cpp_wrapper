#ifndef SDL_CPP_RECTANGLE_COLLIDER_H
#define SDL_CPP_RECTANGLE_COLLIDER_H

#include <SDL2/SDL.h>
#include <cstddef>

namespace sdl
{
    class rectangle_collider
    {
    public:
        static std::size_t const number_of_collider_points = 5;
        using collider_t = SDL_Point [number_of_collider_points];

    private:
        collider_t collider_shape;
        collider_t scaled_collider;
        collider_t rotated_collider;
        collider_t translated_collider;

        double scale_transform{1.0};
        double rotate_transform{0};
        int translate_x_transform{0};
        int translate_y_transform{0};
        bool recalculate_needed{true};

        void apply_transforms();

    public:
        enum class anchor_point
        {
            top_left,
            top_right,
            bottom_left,
            bottom_right,
            center
        };
        rectangle_collider(int width, int height, anchor_point anchor);

        void set_scale(double scale, bool recalculate = true);
        void set_rotation(double rotation, bool recalculate = true);
        void set_translation(int x, int y, bool recalculate = true);
        void set_translation(SDL_Point translation, bool recalculate = true);

        collider_t const& collider();

        bool hit_by(SDL_Point point);
    };
}

#endif //SDL_CPP_RECTANGLE_COLLIDER_H
