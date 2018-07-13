#include "sdl_cpp/rectangle_collider.h"
#include "sdl_cpp/collision_detection.h"
#include "sdl_cpp/point_transforms.h"

namespace sdl
{
	rectangle_collider::rectangle_collider(int width, int height,
										   anchor_point anchor)
	{
		collider_shape[0].x = 0;
		collider_shape[0].y = 0;

		collider_shape[1].x = width;
		collider_shape[1].y = 0;

		collider_shape[2].x = width;
		collider_shape[2].y = height;

		collider_shape[3].x = 0;
		collider_shape[3].y = height;

		collider_shape[4].x = 0;
		collider_shape[4].y = 0;

		switch (anchor)
		{
		case anchor_point::top_right:
			translate_points(collider_shape, collider_shape,
							 number_of_collider_points, -width, 0);
			break;
		case anchor_point::bottom_left:
			translate_points(collider_shape, collider_shape,
							 number_of_collider_points, 0, -height);
			break;
		case anchor_point::bottom_right:
			translate_points(collider_shape, collider_shape,
							 number_of_collider_points, -width, -height);
			break;
		case anchor_point::center:
			translate_points(collider_shape, collider_shape,
							 number_of_collider_points, -(width / 2),
							 -(height / 2));
			break;
		default:
		case anchor_point::top_left:
			break;
		}
	}

	void rectangle_collider::set_scale(double scale, bool recalculate)
	{
		recalculate_needed = true;

		scale_transform = scale;

		if (recalculate)
			apply_transforms();
	}

	void rectangle_collider::set_rotation(double rotation, bool recalculate)
	{
		recalculate_needed = true;

		rotate_transform = rotation;

		if (recalculate)
			apply_transforms();
	}

	void rectangle_collider::set_translation(int x, int y, bool recalculate)
	{
		recalculate_needed = true;

		translate_x_transform = x;
		translate_y_transform = y;

		if (recalculate)
			apply_transforms();
	}

	void rectangle_collider::set_translation(SDL_Point translation,
											 bool recalculate)
	{
		set_translation(translation.x, translation.y, recalculate);
	}

	void rectangle_collider::apply_transforms()
	{
		scale_points(collider_shape, scaled_collider, number_of_collider_points,
					 scale_transform);
		rotate_points(scaled_collider, rotated_collider,
					  number_of_collider_points, rotate_transform);
		translate_points(rotated_collider, translated_collider,
						 number_of_collider_points, translate_x_transform,
						 translate_y_transform);
		recalculate_needed = false;
	}

	rectangle_collider::collider_t const& rectangle_collider::collider()
	{
		if (recalculate_needed)
			apply_transforms();

		return translated_collider;
	}

	bool rectangle_collider::hit_by(SDL_Point point)
	{
		auto final_collider = collider();

		return tri_point_collision(&final_collider[0], point) ||
			   tri_point_collision(&final_collider[2], point);
	}
}