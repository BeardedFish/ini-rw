// File Name:     Validation.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	/// <summary>
	/// The character than an INI section name must starts with.
	/// </summary>
	constexpr const char SECTION_BEGINNING_CHAR = '[';

	/// <summary>
	/// The character that an INI section name must end with.
	/// </summary>
	constexpr const char SECTION_ENDING_CHAR = ']';

	/// <summary>
	/// Checks whether a string is a valid INI key or not. A valid INI key has the format: "KEY_NAME=KEY_VALUE" (excluding quotes). A valid key must also be at minimum three
	/// characters in length.
	/// </summary>
	/// <param name="str">The string to be evaluated.</param>
	/// <returns>True if the string is a valid INI key, if not, false.</returns>
	bool IsValidIniKey(const std::string& str);

	/// <summary>
	/// Checks whether a string is a valid INI section or not. A valid INI section begins with the character defined in the SECTION_BEGINNING_CHAR constant variable and ends
	/// with the character defined in the SECTION_ENDING_CHAR constant.
	/// </summary>
	/// <param name="str">The string to be evaluated.</param>
	/// <returns>True if the string is a valid INI section, if not, false.</returns>
	bool IsValidIniSection(const std::string& str);

	/// <summary>
	/// Compares two strings to see if they are equal. This function ignores case. The strings are compared letter by letter, where each letter is lowercased before being
	/// compared.
	/// </summary>
	/// <param name="str1">The string to be compared to the second string.</param>
	/// <param name="str2">The string to be compared to the first string.</param>
	/// <returns>True if the strings are equal (ignoring case), if not, false.</returns>
	bool EqualsIgnoreCase(const std::string& str1, const std::string& str2);
}