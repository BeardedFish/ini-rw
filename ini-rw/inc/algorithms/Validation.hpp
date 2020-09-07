// File Name:     Validation.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	constexpr char SECTION_BEGINNING_CHAR = '[';

	constexpr char SECTION_ENDING_CHAR = ']';

	bool IsValidIniKey(const std::string& str);

	bool EqualsIgnoreCase(const std::string& str1, const std::string& str2);
}