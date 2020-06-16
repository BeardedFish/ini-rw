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

	size_t Section::GetSectionLocation(std::vector<IniEntity>& iniContents, const std::string& sectionName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i].GetType() == IniEntityType::Section)
			{
				if (*static_cast<std::string*>(iniContents[i].GetData()) == sectionName)
				{
					return i;
				}
			}
		}


		return SECTION_NOT_FOUND;
	}

	std::string Section::ExtractSectionName(const std::string& section)
	{
		return section.substr(1, section.length() - 2);
	}

	std::string Section::GetFormatted(const std::string& name)
	{
		return SECTION_BEGINNING + name + SECTION_ENDING;
	}
}