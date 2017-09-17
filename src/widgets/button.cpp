#include "sdl_cpp/widgets/button.h"
#include "sdl_cpp/point_transforms.h"

namespace sdl
{
    namespace widgets
    {
        button::button(std::string const& text)
            : resizable_widget{0, 0}
            , text_widget{0, 0, text}
            , outline_points{{0, 0}, {100, 0}, {100, 100}, {0, 100}, {0, 0}}
        {
            set_size_based_on_text();
            current_application()->mouse_events.add_mouse_button_event_handler(*this);
        }

        button::button(int x, int y, std::string const& text)
            : resizable_widget{x, y}
            , text_widget{x, y, text}
            , outline_points{{0, 0}, {100, 0}, {100, 100}, {0, 100}, {0, 0}}
        {
            set_size_based_on_text();
            current_application()->mouse_events.add_mouse_button_event_handler(*this);
        }

        button::~button()
        {
            current_application()->mouse_events.remove_mouse_button_event_handler(*this);
        }

        void button::click_handler(event_handler handler)
        {
            click_event_handler = handler;
        }

        void button::clear_click_handler()
        {
            click_event_handler = event_handler();
        }

        std::string const& button::text() const
        {
            return text_widget.text();
        }

        void button::text(std::string const& text)
        {
            text_widget.text(text);
        }

        void button::draw()
        {
        }

        void button::refresh()
        {
            text_widget.refresh();
            set_size_based_on_text();
        }

        void button::x(int value)
        {
            widget::x(value);
            text_widget.x(value);
            set_outline_points();
        }

        void button::y(int value)
        {
            widget::y(value);
            text_widget.y(value);
            set_outline_points();
        }

        void button::width(int value)
        {
            resizable_widget::width(value);
            set_outline_points();
        }

        void button::height(int value)
        {
            resizable_widget::height(value);
            set_outline_points();
        }

        void button::show()
        {
            widget::show();
            text_widget.show();
            outline.show();
        }

        void button::hide()
        {
            widget::hide();
            text_widget.hide();
            outline.hide();
        }

        void button::set_size_based_on_text()
        {
            dimensions.w = text_widget.width();
            dimensions.h = text_widget.height();

            set_outline_points();
        }

        void button::set_outline_points()
        {
            outline_points[0].x = 0;
            outline_points[0].y = 0;

            outline_points[1].x = dimensions.w;
            outline_points[1].y = 0;

            outline_points[2].x = dimensions.w;
            outline_points[2].y = dimensions.h;

            outline_points[3].x = 0;
            outline_points[3].y = dimensions.h;

            outline_points[4].x = 0;
            outline_points[4].y = 0;

            translate_points(outline_points, outline_points, number_of_outline_points, dimensions.x, dimensions.y);
        }

        void button::mouse_button_pressed_event(Uint32 mouse_id, mouse_button button,
                                                Uint8 clicks, Sint32 x, Sint32 y)
        {
            (void)mouse_id;
            (void)clicks;
            if(is_visible && button == mouse_button::left)
            {
                SDL_Point mouse_point{x, y};
                bool hit = tri_point_collision(&outline_points[0], mouse_point) ||
                        tri_point_collision(&outline_points[2], mouse_point);

                if(hit && click_event_handler)
                {
                    click_event_handler(*this);
                }

            }
        }

        void button::mouse_button_released_event(Uint32 mouse_id, mouse_button button,
                                                 Uint8 clicks, Sint32 x, Sint32 y)
        {
            (void)mouse_id;
            (void)button;
            (void)clicks;
            (void)x;
            (void)y;
        }

    }
}
