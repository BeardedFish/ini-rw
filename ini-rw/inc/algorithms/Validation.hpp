// File Name:     Validation.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	/// <summary>
	/// Compares two strings for equality, ignoring case.
	/// </summary>
	/// <param name="str1">The string to be compared to the second string.</param>
	/// <param name="str2">The string to be compared to the first string.</param>
	/// <returns>True if the strings are equal (ignoring case), if not, false.</returns>
	bool EqualsIgnoreCase(const std::string& str1, const std::string& str2);
}