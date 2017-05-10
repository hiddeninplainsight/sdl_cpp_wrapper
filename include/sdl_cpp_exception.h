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

#endif //SDL_CPP_EXCEPTION_H
