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

    SDL_Point collider[4] =
    {
        { 100, 100 },
        { 200, 100 },
        { 150, 150 },
        { 100, 100 }
    };

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
        sdl::key_state a_key{events, SDLK_a};
        sdl::key_state d_key{events, SDLK_d};

        SDL_Point location{10, 10};

        while(!quit)
        {
            events.poll();

            if(w_key)
            {
                --location.y;
                if(sdl::tri_point_collision(collider, location))
                {
                    ++location.y;
                }
            }

            if(s_key)
            {
                ++location.y;
                if(sdl::tri_point_collision(collider, location))
                {
                    --location.y;
                }
            }

            if(a_key)
            {
                --location.x;
                if(sdl::tri_point_collision(collider, location))
                {
                    ++location.x;
                }
            }

            if(d_key)
            {
                ++location.x;
                if(sdl::tri_point_collision(collider, location))
                {
                    --location.x;
                }
            }

            renderer.set_draw_colour(0xAA, 0xAA, 0xAA);
            renderer.clear();

            renderer.copy(circleTexture, location.x, location.y);

            renderer.set_draw_colour(0xFF, 0x00, 0x00);
            renderer.draw_lines(collider);

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