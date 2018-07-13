#ifndef SDL_CPP_MOUSE_STATE_H
#define SDL_CPP_MOUSE_STATE_H

#include "event_mouse_dispatch.h"
#include "events.h"

#include <map>

namespace sdl
{
	struct mouse_button_state
	{
		Uint8 clicks{0};
		Sint32 x{0};
		Sint32 y{0};
	};

	class mouse_state : public mouse_motion_event_handler,
						public mouse_button_event_handler,
						public mouse_wheel_event_handler
	{
	private:
		event_mouse_dispatch& mouse_events;
		Sint32 x_coordinate{0};
		Sint32 y_coordinate{0};
		Sint32 x_wheel{0};
		Sint32 y_wheel{0};
		std::map<mouse_button, mouse_button_state> button_state_pressed;
		std::map<mouse_button, mouse_button_state> button_state_released;

	public:
		explicit mouse_state(event_mouse_dispatch& mouse_events);
		~mouse_state() override;

		mouse_state(const mouse_state&) = delete;
		mouse_state& operator=(const mouse_state&) = delete;

		virtual void mouse_motion_event(Uint32 mouse_id, Uint32 button_state,
										Sint32 x, Sint32 y, Sint32 x_relative,
										Sint32 y_relative) override;
		virtual void mouse_button_pressed_event(Uint32 mouse_id,
												mouse_button button,
												Uint8 clicks, Sint32 x,
												Sint32 y) override;
		virtual void mouse_button_released_event(Uint32 mouse_id,
												 mouse_button button,
												 Uint8 clicks, Sint32 x,
												 Sint32 y) override;
		virtual void mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y,
									   Uint32 direction) override;

		mouse_button_state button_press(mouse_button button,
										bool clear = false);
		mouse_button_state button_release(mouse_button button,
										  bool clear = false);

		Sint32 x() const { return x_coordinate; }
		Sint32 y() const { return y_coordinate; }
		Sint32 wheel_x() const { return x_wheel; }
		Sint32 wheel_y() const { return y_wheel; }
	};
}

// clang-format off
/*
@startuml
namespace sdl {
	class mouse_state {
		+ mouse_state(events& events_system)
		+ void mouse_motion_event(Uint32 mouse_id, Uint32 button_state, Sint32 x, Sint32 y, Sint32 x_relative, Sint32 y_relative)
		+ void mouse_button_pressed_event(Uint32 mouse_id, Uint8 button, Uint8 clicks, Sint32 x, Sint32 y)
		+ void mouse_button_released_event(Uint32 mouse_id, Uint8 button, Uint8 clicks, Sint32 x, Sint32 y)
		+ void mouse_wheel_event(Uint32 mouse_id, Sint32 x, Sint32 y, Uint32 direction)
		+ mouse_button_state button_press(mouse_button button, bool clear = false)
		+ mouse_button_state button_release(mouse_button button, bool clear = false)
		+ Sint32 x() const
		+ Sint32 y() const
		+ Sint32 wheel_x() const
		+ Sint32 wheel_y() const
	}

	class mouse_button_state << (S,#FF7700) struct >> {
		Uint8 clicks
		Sint32 x
		Sint32 y
	}
	hide mouse_button_state methods

	mouse_button <-- mouse_state
	mouse_button_state <-- mouse_state

	event_mouse_dispatch <..o mouse_state
	mouse_motion_event_handler <|.. mouse_state
	mouse_button_event_handler <|.. mouse_state
	mouse_wheel_event_handler <|.. mouse_state
}
@enduml
*/
// clang-format on

#endif  // SDL_CPP_MOUSE_STATE_H
