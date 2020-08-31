// File Name:     IniSectionAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include <string>

namespace IniRW
{
	constexpr char SECTION_BEGINNING = '[';
	constexpr char SECTION_ENDING = ']';
	constexpr size_t SECTION_NOT_FOUND = -1;

	bool IsValidIniSection(const std::string& str);

	std::string ExtractSectionName(const std::string& section);

}