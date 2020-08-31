// File Name:     IniSectionAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniSectionAlgorithms.hpp"

namespace IniRW
{
	bool IsValidIniSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == SECTION_BEGINNING && str[str.length() - 1] == SECTION_ENDING;
	}

	std::string ExtractSectionName(const std::string& section)
	{
		if (!IsValidIniSection(section))
		{
			return section;
		}

		return section.substr(1, section.length() - 2);
	}
}