#ifndef SDL_CPP_WIDGETS_BUTTON_H
#define SDL_CPP_WIDGETS_BUTTON_H

#include "resizable_widget.h"
#include "label.h"
#include "lines_no_storage.h"
#include "../fonts/ttf_font.h"
#include "../event_mouse_dispatch.h"

#include <functional>

namespace sdl
{
    namespace widgets
    {
        class button : public resizable_widget, private ::sdl::mouse_button_event_handler
        {
        public:
            using event_handler = std::function<void(button&)>;

        private:
            label text_widget;
            static const int number_of_outline_points = 5;
            SDL_Point outline_points[number_of_outline_points];
            lines_no_storage outline{outline_points};

            event_handler click_event_handler;

        public:
            explicit button(std::string const& text = " ");
            button(int x, int y, std::string const& text = " ");
            virtual ~button() override;

            void click_handler(event_handler handler);
            void clear_click_handler();

            std::string const& text() const;
            void text(std::string const& text);

            virtual void draw() override;
            virtual void refresh() override;

            virtual void width(int value) override;
            virtual void height(int value) override;

            virtual void show() override;
            virtual void hide() override;

            void set_size_based_on_text();

        private:
            void set_outline_points();

            virtual void mouse_button_pressed_event(Uint32 mouse_id, mouse_button button,
                                                    Uint8 clicks, Sint32 x, Sint32 y) override;
            virtual void mouse_button_released_event(Uint32 mouse_id, mouse_button button,
                                                     Uint8 clicks, Sint32 x, Sint32 y) override;
        };
    }
}

#endif //SDL_CPP_WIDGETS_BUTTON_H
