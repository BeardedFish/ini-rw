// File Name:     IniSection.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/entities/IniSection.hpp"
#include "../../inc/algorithms/Validation.hpp"

namespace IniRW
{
	IniSection::IniSection(const std::string& name) : IniEntity()
	{
		this->name = name;
	}

	IniSection::~IniSection()
	{
		// TODO: Deallocate the right side data if it exists
	}

	IniEntityType IniSection::GetType()
	{
		return IniEntityType::Section;
	}

	std::string IniSection::ToString() const
	{
		return SECTION_BEGINNING_CHAR + GetName() + SECTION_ENDING_CHAR;
	}

	std::string IniSection::GetName() const
	{
		return name;
	}
}