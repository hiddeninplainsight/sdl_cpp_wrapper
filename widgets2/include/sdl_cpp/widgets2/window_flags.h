#ifndef SDL_CPP_WRAPPER_WINDOW_FLAGS_H
#define SDL_CPP_WRAPPER_WINDOW_FLAGS_H

#include <type_traits>

namespace sdl
{
	namespace widgets2
	{
		enum class window_flags
		{
			none,
			fixed_size = 1 << 0
		};

		constexpr inline window_flags operator|(window_flags lhs,
												window_flags rhs)
		{
			using T = std::underlying_type_t<window_flags>;
			return static_cast<window_flags>(static_cast<T>(lhs) |
											 static_cast<T>(rhs));
		}

		constexpr inline window_flags& operator|=(window_flags& lhs,
												  window_flags rhs)
		{
			lhs = lhs | rhs;
			return lhs;
		}

		constexpr inline window_flags operator&(window_flags lhs,
												window_flags rhs)
		{
			using T = std::underlying_type_t<window_flags>;
			return static_cast<window_flags>(static_cast<T>(lhs) &
											 static_cast<T>(rhs));
		}
	}
}

#endif	// SDL_CPP_WRAPPER_WINDOW_FLAGS_H
