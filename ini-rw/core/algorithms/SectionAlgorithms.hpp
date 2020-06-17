// File Name:     SectionAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include "../IniEntity.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	constexpr char SECTION_BEGINNING = '[';
	constexpr char SECTION_ENDING = ']';
	constexpr size_t SECTION_NOT_FOUND = -1;

	bool IsSection(const std::string& str);
	size_t GetSectionLocation(std::vector<IniEntity>& iniContents, const std::string& sectionName);

	std::string ExtractSectionName(const std::string& section);
	std::string GetFormatted(const std::string& name);
} // End IniRW namespace