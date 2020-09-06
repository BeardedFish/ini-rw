// File Name:     IniSection.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/entities/IniSection.hpp"
#include "../../inc/algorithms/Validation.hpp"

namespace IniRW
{
	IniSection::IniSection(const std::string& iniLine) : IniEntity()
	{
		this->name = iniLine;
	}

	IniEntityType IniSection::GetType()
	{
		return IniEntityType::Section;
	}

	std::string IniSection::ToString() const
	{
		return SECTION_BEGINNING_CHAR + GetName() + SECTION_ENDING_CHAR + extraData.ToString();
	}

	std::string IniSection::GetName() const
	{
		return name;
	}
}