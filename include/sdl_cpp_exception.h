#ifndef SDL_CPP_EXCEPTION_H
#define SDL_CPP_EXCEPTION_H

#include <exception>

namespace sdl
{
    class sdl_exception : public std::exception
    {
        const char *method;
        const char *message;
    public:
        sdl_exception(const char *method, const char *message)
                : method{method}
                , message{message}
        {
        }

        const char * source_method() const noexcept { return method; }
        const char * what() const noexcept override { return message; }
    };
}

/*
@startuml
namespace sdl {
    class sdl_exception {
        + sdl_exception(const char *method, const char *message)
        + const char * source_method() const noexcept
        + const char * what() const noexcept override
    }

    sdl_exception --|> std::exception
}

namespace std {
    hide exception methods
    hide exception fields
}
@enduml
*/

#endif //SDL_CPP_EXCEPTION_H
