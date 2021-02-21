#ifndef FREETYPE_CPP_FREETYPE_POINTS_H
#define FREETYPE_CPP_FREETYPE_POINTS_H

#include "internal/safetype.h"
#include "internal/literal_parser.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace freetype_cpp
{
	using points =
		internal::safe_type_scaled<FT_F26Dot6, struct points_tag, 64>;
}

template<char... literal>
constexpr freetype_cpp::points operator ""_points()
{
	auto const value =
		freetype_cpp::internal::literal_parser<literal...>::value;

	static_assert(value <= freetype_cpp::points::max,
				  "value too large for freetype_cpp::points");

	return freetype_cpp::points(value);
}

#endif	// FREETYPE_CPP_FREETYPE_POINTS_H
