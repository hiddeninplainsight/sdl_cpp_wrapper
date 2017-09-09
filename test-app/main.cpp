#include <sdl_cpp_widgets_window_application.h>
#include <sdl_cpp.h>
#include <sdl_cpp_ttf_font_context.h>
#include <sdl_cpp_ttf_font.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class test_application : public sdl::widgets::window_application
{
private:
    using collider_t = SDL_Point[4];

    collider_t const collider_shape
            {
                    { -50, -25 },
                    { 50, -25 },
                    { 0, 25 },
                    { -50, -25 }
            };

    collider_t collider;

    sdl::ttf_font_context ttf_context;
    sdl::ttf_font press_start_2p_font{application_path + "/PressStart2P-Regular.ttf", 36};

    sdl::texture circleTexture{renderer, sdl::surface::create_from_image(application_path + "/circle.png")};

    sdl::key_state w_key{keys, SDLK_w};
    sdl::key_state s_key{keys, SDLK_s};
    sdl::key_state a_key{keys, SDLK_a};
    sdl::key_state d_key{keys, SDLK_d};
    sdl::key_state q_key{keys, SDLK_q};
    sdl::key_state e_key{keys, SDLK_e};

    sdl::mouse_state mouse{mouse_events};

    SDL_Point location{10, 10};
    double angle = 0.0;

    void rotate_collider(double change)
    {
        angle += change;

        if(angle < 0.0) angle += 360.0;
        if(angle > 360.0) angle -= 360.0;

        sdl::scale_points(collider_shape, collider, 4, 1.2);
        sdl::rotate_points(collider, collider, 4, angle);
        sdl::translate_points(collider, collider, 4, 200, 200);
    };

    void attempt_move(SDL_Point const& transform)
    {
        SDL_Point new_location = location + transform;
        if(!sdl::tri_point_collision(collider, new_location))
        {
            location = new_location;
        }
    };

protected:
    void process_events() override
    {
        if(q_key) rotate_collider(-1.0);
        if(e_key) rotate_collider(1.0);

        if(w_key) attempt_move({0, -1});
        if(s_key) attempt_move({0, 1});
        if(a_key) attempt_move({-1, 0});
        if(d_key) attempt_move({1, 0});
    }

    void process_graphics() override
    {
        renderer.set_draw_colour(0xAA, 0xAA, 0xAA);
        renderer.clear();

        renderer.copy(circleTexture, location.x, location.y);

        renderer.set_draw_colour(0xFF, 0x00, 0x00);
        renderer.draw_lines(collider);

        std::string mouse_location = std::to_string(mouse.x()) + ", " + std::to_string(mouse.y()) + " : " +
                                     std::to_string(mouse.wheel_x()) + ", " + std::to_string(mouse.wheel_y());
        sdl::texture mouse_location_texture = press_start_2p_font.create_texture(renderer, mouse_location, {0x00, 0x00, 0x00});
        renderer.copy(mouse_location_texture, 10, 10);

        std::stringstream mouse_clicks;
        mouse_clicks << static_cast<unsigned int>(mouse.button_press(sdl::mouse_button::left).clicks) << "," ;
        mouse_clicks << mouse.button_press(sdl::mouse_button::left).x << ",";
        mouse_clicks << mouse.button_press(sdl::mouse_button::left).y;
        auto mouse_clicks_texture = press_start_2p_font.create_texture(renderer, mouse_clicks.str(), {0x00, 0x00, 0x00});
        renderer.copy(mouse_clicks_texture, 10, 100);

        mouse_clicks = std::stringstream();
        mouse_clicks << static_cast<unsigned int>(mouse.button_release(sdl::mouse_button::left).clicks) << "," ;
        mouse_clicks << mouse.button_release(sdl::mouse_button::left).x << ",";
        mouse_clicks << mouse.button_release(sdl::mouse_button::left).y;
        mouse_clicks_texture = press_start_2p_font.create_texture(renderer, mouse_clicks.str(), {0x00, 0x00, 0x00});
        renderer.copy(mouse_clicks_texture, 10, 200);
    }

public:
    test_application(int argc, char** argv, std::string const& title, int x, int y, int width, int height)
        : window_application(argc, argv, title, x, y, width, height)
    {
        rotate_collider(0.0);
    }
};

int main(int argc, char** argv)
{
    try
    {
        test_application application{argc, argv, "test-app", 100, 100, 800, 480};
        return application.run();
    }
    catch(sdl::sdl_exception const& error)
    {
        std::cerr << "SDL Exception : " << error.what() << std::endl;
        return sdl::widgets::exit_code::sdl_exception;
    }
}