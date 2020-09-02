// File Name:     IniSectionAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniSectionAlgorithms.hpp"
#include "../IniComment.hpp"
#include "../IniSection.hpp"

namespace IniRW
{
	bool IsValidIniSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == SECTION_BEGINNING_CHAR && str[str.length() - 1] == SECTION_ENDING_CHAR;
	}

	size_t GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i]->GetType() == IniEntityType::Section)
			{
				if (static_cast<IniComment*>(iniContents[i])->GetText() == sectionName)
				{
					return i;
				}
			}
		}

		return SECTION_NOT_FOUND;
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