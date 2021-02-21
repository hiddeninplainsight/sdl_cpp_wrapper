#ifndef FREETYPE_CPP_FREETYPE_SAFETYPE_H
#define FREETYPE_CPP_FREETYPE_SAFETYPE_H

#include <limits>

namespace freetype_cpp
{
	namespace internal
	{
		template <class T, class tag>
		class safe_type
		{
		private:
			T value;

		public:
			using type = T;

			constexpr explicit safe_type(T value)
				: value{value}
			{
			}

			constexpr explicit operator T() const { return value; }
		};

		template <class T, class tag, T scale>
		class safe_type_scaled : public safe_type<T, tag>
		{
		public:
			static T const scale = scale;
			static T const max = std::numeric_limits<T>::max() / scale;

			constexpr explicit safe_type_scaled(T value)
				: safe_type<T, tag>{value * scale}
			{
			}
		};
	}
}

#endif	// FREETYPE_CPP_FREETYPE_SAFETYPE_H
