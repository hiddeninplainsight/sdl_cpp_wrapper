#include <sdl_cpp/widgets2/application.h>
#include <sdl_cpp/widgets2/window.h>
#include <sdl_cpp/widgets2/widget.h>
#include <sdl_cpp/widgets2/panel.h>
#include <sdl_cpp/renderer.h>
#include <sdl_cpp/texture.h>
#include <sdl_cpp/texture_pixel_buffer.h>
#include <sdl_cpp/pixel_buffer_painter.h>
#include <memory>

#include <memory>
#include <string>

using namespace std;
using namespace sdl::widgets2;

class pixel_buffer_widget : public widget
{
private:
	unique_ptr<sdl::texture> texture_ptr;

	void update_texture()
	{
		sdl::texture_pixel_buffer pixels{texture_ptr.get()};
		pixels.clear(0x009900FF);

		auto painter =
			sdl::pixel_buffer_painter::from_texture_pixel_buffer(pixels);

		painter.line(10,5,300,200, 0xFFFFFFFF);

		int const radius = (requested_position.w / 2) - 10;
		int const x_and_y = requested_position.w / 2;

		painter.circle(x_and_y, x_and_y, radius, 0xFFFFFFFF, 2);

		painter.filled_circle(x_and_y, x_and_y, radius - 10, 0xFFFFFFFF);

		painter.filled_rectangle(50, 50, requested_position.w - 100,
								 requested_position.h - 100, 0x000099FF);

		Uint32 colour1 = 0xFF0000FF;
		auto b = pixels.buffer;
		for (int y = 0; y < pixels.size.height; ++y)
		{
			for (int x = 0; x < pixels.size.width; ++x)
			{
				if ((x / 20) % 2 == 0 && (y / 20) % 2 == 0)
				{
					*b = colour1;
				}
				++b;
			}
		}

		pixels.update_texture();
	}

public:
	void set_renderer(sdl::renderer* r) override
	{
		texture_ptr = nullptr;
		widget::set_renderer(r);
		texture_ptr = make_unique<sdl::texture>(
			*sdl_renderer, requested_position.w, requested_position.h);
		update_texture();
	}

	void draw() override { sdl_renderer->copy(*texture_ptr, screen_position); }
};

class main_window : public window
{
public:
	shared_ptr<panel> root_container;
	shared_ptr<widget> widget1;

	main_window(string const& title, int x, int y, int width, int height)
		: window(title, x, y, width, height)
		, root_container{make_shared<panel>()}
	{
		set_root_widget(root_container);

		widget1 = make_shared<pixel_buffer_widget>();
		widget1->position(10, 10);
		widget1->dimensions(500, 500);
		root_container->add_widget(widget1);
	}
};

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	application app;
	app.create_window<main_window>("Demo app", 0, 50, 640, 480);
	app.run();

	return 0;
}
