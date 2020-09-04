// File Name:     IniNewLine.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/entities/IniNewLine.hpp"

namespace IniRW
{
	IniEntityType IniNewLine::GetType()
	{
		return IniEntityType::NewLine;
	}

	std::string IniNewLine::ToString() const
	{
		return "\n";
	}
}