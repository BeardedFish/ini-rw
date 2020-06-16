// File Name:     Section.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#include "Section.hpp"

namespace IniRW
{
	bool Section::IsSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == SECTION_BEGINNING && str[str.length() - 1] == SECTION_ENDING;
	}

	std::string Section::ExtractSectionName(const std::string& section)
	{
		return section.substr(1, section.length() - 2);
	}
}