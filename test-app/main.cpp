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

    using collider_t = SDL_Point[4];

    collider_t const collider_shape =
    {
        { -50, -25 },
        { 50, -25 },
        { 0, 25 },
        { -50, -25 }
    };

    collider_t collider;

    try
    {
        sdl::context context;

        sdl::window window{"test-app", 100, 100, 640, 480};
        sdl::renderer renderer{window};
        sdl::texture circleTexture{renderer, sdl::surface::create_from_image(application_path + "/circle.png")};

        sdl::events events;
        sdl::quit_event_bool quit{events};
        sdl::event_keys keys{events};
        sdl::key_state w_key{keys, SDLK_w};
        sdl::key_state s_key{keys, SDLK_s};
        sdl::key_state a_key{keys, SDLK_a};
        sdl::key_state d_key{keys, SDLK_d};
        sdl::key_state q_key{keys, SDLK_q};
        sdl::key_state e_key{keys, SDLK_SPACE};
        e_key.change_key(SDLK_e);

        SDL_Point location{10, 10};
        double angle = 0.0;

        auto rotate_collider = [&collider_shape, &collider, &angle](double change)
        {
            angle += change;

            if(angle < 0.0) angle += 360.0;
            if(angle > 360.0) angle -= 360.0;

            sdl::scale_points(collider_shape, collider, 4, 1.2);
            sdl::rotate_points(collider, collider, 4, angle);
            sdl::translate_points(collider, collider, 4, 200, 200);
        };

        auto attempt_move = [&collider, &location](SDL_Point const& transform)
        {
            SDL_Point new_location = location + transform;
            if(!sdl::tri_point_collision(collider, new_location))
            {
                location = new_location;
            }
        };

        rotate_collider(0.0);

        while(!quit)
        {
            events.poll();

            if(q_key) rotate_collider(-1.0);
            if(e_key) rotate_collider(1.0);

            if(w_key) attempt_move({0, -1});
            if(s_key) attempt_move({0, 1});
            if(a_key) attempt_move({-1, 0});
            if(d_key) attempt_move({1, 0});

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