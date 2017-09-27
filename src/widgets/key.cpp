#include "sdl_cpp/widgets/key.h"

namespace sdl
{
    namespace widgets
    {
        application *key::current_application()
        {
            if (application::current == nullptr)
            {
                throw sdl_exception{"key::current_application", "Attempted to create key with no active application"};
            }
            return application::current;
        }

        key::key(SDL_Keycode keyCode)
            : keyState{current_application()->keys, keyCode}
        {
        }

        bool key::down() const
        {
            return keyState;
        }

        void key::clear_down()
        {
            keyState.clear_down();
        }
    }
}
