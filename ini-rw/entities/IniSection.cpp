// File Name:     IniSection.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "IniSection.hpp"

namespace IniRW
{
	IniSection::IniSection(const std::string& name) : IniEntity()
	{
		this->name = name;
	}

	std::string IniSection::GetName()
	{
		// TODO: Replace [ and ] with constant variables...

		return "[" + name + "]";
	}

	IniEntityType IniSection::GetType()
	{
		return IniEntityType::Section;
	}
}