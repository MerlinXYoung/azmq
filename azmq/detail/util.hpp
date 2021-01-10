#pragma once 
#include <type_traits>
#include <vector>
// #include <string>
namespace azmq{
namespace detail{
	template <typename Enumeration>
	inline constexpr auto enum_to_int(Enumeration const value) ->
		typename std::underlying_type<Enumeration>::type
	{
		return static_cast<typename std::underlying_type<Enumeration>::type>(value);
	}


	/**
	 * @function : Splits the string into multiple strings with the specified delimiters
	 */
	template<class String, class Delimiter>
	inline std::vector<String> split(const String& s, const Delimiter& delimiters = " ")
	{
		using size_type = typename String::size_type;
		std::vector<String> tokens;
		size_type last_pos = s.find_first_not_of(delimiters, 0);
		size_type pos = s.find_first_of(delimiters, last_pos);
		while (String::npos != pos || String::npos != last_pos)
		{
			tokens.emplace_back(s.substr(last_pos, pos - last_pos));
			last_pos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, last_pos);
		}
		return tokens;
	}

	/**
	 * @function : Splits the string into multiple strings with the specified delimiters
	 */
	template<class String, class Delimiter>
	inline std::vector<String>& split_to(std::vector<String>& tokens, const String& s, const Delimiter& delimiters = " ")
	{
		using size_type = typename String::size_type;
		size_type last_pos = s.find_first_not_of(delimiters, 0);
		size_type pos = s.find_first_of(delimiters, last_pos);
		while (String::npos != pos || String::npos != last_pos)
		{
			tokens.emplace_back(s.substr(last_pos, pos - last_pos));
			last_pos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, last_pos);
		}
		return tokens;
	}

}
}