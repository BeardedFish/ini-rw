// File Name:     IniString.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#include "../../inc/entities/IniString.hpp"

namespace IniRW
{
	IniString::IniString(const std::string& value)
	{
		this->value = value;
	}

	IniEntityType IniString::GetType()
	{
		return IniEntityType::String;
	}

	std::string IniString::ToString() const
	{
		return value;
	}
}