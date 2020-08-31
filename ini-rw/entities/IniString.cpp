// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniString.hpp"

namespace IniRW
{
	IniString::IniString(IniStringType type, const const std::string& text) : IniEntity(type)
	{
		this->text = text;
	}

	std::string IniString::GetText() const
	{
		return text;
	}
}