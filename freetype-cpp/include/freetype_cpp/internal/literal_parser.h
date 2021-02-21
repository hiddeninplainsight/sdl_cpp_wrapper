#ifndef FREETYPE_CPP_FREETYPE_INTERNAL_LITERAL_PARSER_H
#define FREETYPE_CPP_FREETYPE_INTERNAL_LITERAL_PARSER_H

namespace freetype_cpp
{
	namespace internal
	{
		namespace parser
		{
			constexpr unsigned long long add_char_to_sum(unsigned long long sum,
														 char first)
			{
				return (sum * 10) + (first - '0');
			}

			template <unsigned long long sum, char... chars>
			struct literal_parser;

			template <unsigned long long sum, char first, char... chars>
			struct literal_parser<sum, first, chars...>
			{
				static_assert(first >= '0', "Invalid char in literal");
				static_assert(first <= '9', "Invalid char in literal");

				static unsigned long long const value =
					literal_parser<add_char_to_sum(sum, first),
						chars...>::value;
			};

			template <unsigned long long sum>
			struct literal_parser<sum>
			{
				static unsigned long long const value = sum;
			};
		}  // namespace internal

		template <char... chars>
		struct literal_parser
		{
			static unsigned long long const value =
				parser::literal_parser<0, chars...>::value;
		};
	}  // namespace internal
}  // namespace freetype_cpp

#endif	// FREETYPE_CPP_FREETYPE_INTERNAL_LITERAL_PARSER_H
