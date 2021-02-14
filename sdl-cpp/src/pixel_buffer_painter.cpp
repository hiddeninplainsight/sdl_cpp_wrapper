#include "sdl_cpp/pixel_buffer_painter.h"
#include <algorithm>
#include <cmath>

namespace sdl
{
	bool pixel_buffer_painter::range_check(int& x, int& y, int& width,
										   int& height) const
	{
		if (width <= 0 || height <= 0)
			return false;

		if (x < 0)
		{
			width += x;	 // x will be negative so this will subtract
			x = 0;
		}

		int x_overflow = (x + width) - size.width;
		if (x_overflow > 0)
		{
			width -= x_overflow;
		}

		if (y < 0)
		{
			height += y;  // y will be negative so this will subtract
			y = 0;
		}

		int y_overflow = (y + height) - size.height;
		if (y_overflow > 0)
		{
			height -= y_overflow;
		}

		if (width <= 0 || height <= 0)
			return false;

		return true;
	}

	void pixel_buffer_painter::filled_rectangle(int x, int y, int width,
												int height,
												buffer_type colour) const
	{
		if (!range_check(x, y, width, height))
			return;

		int max_y = y + height;
		for (; y < max_y; y++)
		{
			buffer_type* pixel = &buffer[(y * size.width) + x];

			std::fill(pixel, pixel + width, colour);
		}
	}

	void pixel_buffer_painter::rectangle(int x, int y, int width, int height,
				   buffer_type colour) const
	{
		line(x, y, x, y + height, colour);
		line(x + width, y, x + width, y + height, colour);

		line(x, y, x + width, y, colour);
		line(x, y + height, x + width, y + height, colour);
	}

	void pixel_buffer_painter::filled_circle(int center_x, int center_y,
											 int radius,
											 buffer_type colour) const
	{
		int x = center_x - radius;
		int y = center_y - radius;
		int width = radius * 2;
		int height = radius * 2;

		if (!range_check(x, y, width, height))
			return;

		int const min_x = x;
		int const max_x = x + width;
		int const max_y = y + height;
		int const radius2 = radius * radius;

		for (; y < max_y; ++y)
		{
			for (x = min_x; x < max_x; ++x)
			{
				int const dx = center_x - x;
				int const dy = center_y - y;
				int const d = (dx * dx) + (dy * dy);
				if (d <= radius2)
				{
					buffer[(y * size.width) + x] = colour;
				}
			}
		}
	}

	void pixel_buffer_painter::circle(int center_x, int center_y, int radius,
									  buffer_type colour, int line_width) const
	{
		int x = center_x - radius;
		int y = center_y - radius;
		int width = radius * 2;
		int height = radius * 2;

		if (!range_check(x, y, width, height))
			return;

		int const min_x = x;
		int const max_x = x + width;
		int const max_y = y + height;
		int const radius2 = radius * radius;
		int const radius2_inner = (radius - line_width) * (radius - line_width);

		for (; y < max_y; ++y)
		{
			for (x = min_x; x < max_x; ++x)
			{
				int const dx = center_x - x;
				int const dy = center_y - y;
				int const d = (dx * dx) + (dy * dy);
				if ((d >= radius2_inner) && (d <= radius2))
				{
					buffer[(y * size.width) + x] = colour;
				}
			}
		}
	}

	void pixel_buffer_painter::line(int x1, int y1, int x2, int y2,
									buffer_type colour) const
	{
		int const dx = x2 - x1;
		int const dy = y2 - y1;

		int const abs_dx = abs(dx);
		int const abs_dy = abs(dy);

		if(abs_dx > abs_dy)
		{
			for(int x = 0; x < abs_dx; ++x)
			{
				int const px = ((x * dx) / abs_dx) + x1;
				int const py = ((x * dy) / abs_dx) + y1;

				if((px >= 0) && (px < size.width) && (py >= 0) && (py < size.height))
				{
					buffer[(py * size.width) + px] = colour;
				}
			}
		}
		else
		{
			for(int y = 0; y < abs_dy; ++y)
			{
				int const px = ((y * dx) / abs_dy) + x1;
				int const py = ((y * dy) / abs_dy) + y1;

				if((px >= 0) && (px < size.width) && (py >= 0) && (py < size.height))
				{
					buffer[(py * size.width) + px] = colour;
				}
			}
		}
	}

}
