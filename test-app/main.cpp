#include <sdl_cpp.h>
#include <string>
#include <algorithm>
#include <iostream>

struct exit_code
{
    enum
    {
        ok,
        sdl_exception
    };
};

std::string executable_path_to_application_path(std::string const& executable_path)
{
    return std::string{executable_path.cbegin(), executable_path.cbegin() + executable_path.find_last_of('/')};
}

int main(int argc, char** argv)
{
    std::string application_path = executable_path_to_application_path(argv[0]);

    try
    {
        sdl::context context;

        sdl::window window{"test-app", 100, 100, 640, 480};
        sdl::renderer renderer{window};
        sdl::texture circleTexture{renderer, sdl::surface::create_from_image(application_path + "/circle.png")};

        sdl::events events;
        sdl::quit_event_bool quit{events};
        sdl::key_state w_key{events, SDLK_w};
        sdl::key_state s_key{events, SDLK_s};

        int y = 10;

        while(!quit)
        {
            events.poll();

            if(w_key)
                --y;

            if(s_key)
                ++y;

            renderer.clear();
            renderer.copy(circleTexture, 10, y);
            renderer.present();
        }
    }
    catch(sdl::sdl_exception const& error)
    {
        std::cerr << "SDL Exception : " << error.what() << std::endl;
        return exit_code::sdl_exception;
    }

    return exit_code::ok;
}