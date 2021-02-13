#include <sdl_cpp/widgets2/application.h>
#include <sdl_cpp/widgets2/window.h>
#include <sdl_cpp/widgets2/widget.h>
#include <sdl_cpp/widgets2/widget_container.h>

#include <memory>
#include <string>

using namespace std;
using namespace sdl::widgets2;

class main_window : public window
{
public:
	shared_ptr<widget_container> root_container;
	shared_ptr<widget> widget1;

	main_window(string const& title, int x, int y, int width, int height)
		: window(title, x, y, width, height)
		, root_container{make_shared<widget_container>()}
	{
		set_root_widget(root_container);

		widget1 = make_shared<widget>();
		root_container->add_widget(widget1);
	}
};

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	application app;
	app.create_window<main_window>("Demo app", 0, 0, 640, 480);
	app.run();
}
