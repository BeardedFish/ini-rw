// File Name:     Validation.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	constexpr const char SECTION_BEGINNING_CHAR = '[';

	constexpr const char SECTION_ENDING_CHAR = ']';

	bool IsValidIniComment(const std::vector<char>& commentPrefixes, const std::string& str);

	bool IsValidIniKey(const std::string& str);

	bool IsValidIniSection(const std::string& str);
}