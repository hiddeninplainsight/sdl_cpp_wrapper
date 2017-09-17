#include <sdl_cpp/widgets/window_application.h>
#include <sdl_cpp/widgets/label.h>
#include <sdl_cpp/widgets/image.h>
#include <sdl_cpp/widgets/lines_no_storage.h>
#include <sdl_cpp/widgets/button.h>
#include <sdl_cpp/sdl_cpp.h>
#include <sdl_cpp/fonts/ttf_font_context.h>
#include <sdl_cpp/fonts/ttf_font.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class test_application
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

    sdl::widgets::window_application app;

    sdl::widgets::lines_no_storage collider_lines{collider};
    sdl::widgets::image circle{10, 10, app.application_path + "/circle.png"};

    sdl::widgets::label position_label{10, 0};
    sdl::widgets::label pressed_label{10, 100};
    sdl::widgets::label released_label{10, 200};

    sdl::widgets::button reset_button{400, 100, "Reset"};

    sdl::key_state w_key{app.keys, SDLK_w};
    sdl::key_state s_key{app.keys, SDLK_s};
    sdl::key_state a_key{app.keys, SDLK_a};
    sdl::key_state d_key{app.keys, SDLK_d};
    sdl::key_state q_key{app.keys, SDLK_q};
    sdl::key_state e_key{app.keys, SDLK_e};

    sdl::mouse_state mouse{app.mouse_events};

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
        SDL_Point new_location = circle.location() + transform;
        if(!sdl::tri_point_collision(collider, new_location))
        {
            circle.location(new_location);
        }
    };

protected:
    void process_events()
    {
        if(q_key) rotate_collider(-1.0);
        if(e_key) rotate_collider(1.0);

        if(w_key) attempt_move({0, -1});
        if(s_key) attempt_move({0, 1});
        if(a_key) attempt_move({-1, 0});
        if(d_key) attempt_move({1, 0});

        auto right_click = mouse.button_press(sdl::mouse_button::right, true);
        if(right_click.clicks)
        {
            circle.x(right_click.x);
            circle.y(right_click.y);
        }

        std::stringstream  mouse_location;
        mouse_location << std::to_string(mouse.x()) + ", ";
        mouse_location <<std::to_string(mouse.y()) + " : ";
        mouse_location << std::to_string(mouse.wheel_x()) + ", ";
        mouse_location << std::to_string(mouse.wheel_y());
        position_label.text(mouse_location.str());

        std::stringstream pressed_clicks;
        pressed_clicks << static_cast<unsigned int>(mouse.button_press(sdl::mouse_button::left).clicks) << "," ;
        pressed_clicks << mouse.button_press(sdl::mouse_button::left).x << ",";
        pressed_clicks << mouse.button_press(sdl::mouse_button::left).y;
        pressed_label.text(pressed_clicks.str());

        std::stringstream released_clicks;
        released_clicks << static_cast<unsigned int>(mouse.button_release(sdl::mouse_button::left).clicks) << "," ;
        released_clicks << mouse.button_release(sdl::mouse_button::left).x << ",";
        released_clicks << mouse.button_release(sdl::mouse_button::left).y;
        released_label.text(released_clicks.str());
    }

public:
    test_application(int argc, char** argv, std::string const& title, int x, int y, int width, int height)
        : app(argc, argv, title, x, y, width, height)
    {
        rotate_collider(0.0);

        collider_lines.colour({0xFF, 0x00, 0x00, 0xFF});

        app.resize_font(36);

        position_label.refresh();
        pressed_label.refresh();
        released_label.refresh();

        reset_button.refresh();

        reset_button.click_handler([this](sdl::widgets::button&) {
            this->circle.location({10, 10});
            this->angle = 0.0;
            this->rotate_collider(0.0);
        });
    }

    int run()
    {
        while(!app.quit)
        {
            app.events.poll();
            process_events();
            app.draw();
        }
        return 0;
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
        return -1;
    }
}