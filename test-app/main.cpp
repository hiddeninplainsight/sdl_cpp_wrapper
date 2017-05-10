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

        bool runGame{true};
        while(runGame)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        runGame = false;
                        break;
                    default:
                        break;
                }
            }

            renderer.clear();
            renderer.copy(circleTexture, 10, 10);
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