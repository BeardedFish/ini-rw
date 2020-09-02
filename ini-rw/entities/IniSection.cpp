// File Name:     IniSection.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "IniSection.hpp"
#include "../algorithms/IniSectionAlgorithms.hpp"

namespace IniRW
{
	IniSection::IniSection(const std::string& name) : IniEntity()
	{
		this->name = name;
	}

	std::string IniSection::GetName()
	{
		return SECTION_BEGINNING_CHAR + name + SECTION_ENDING_CHAR;
	}

	IniEntityType IniSection::GetType()
	{
		return IniEntityType::Section;
	}
}