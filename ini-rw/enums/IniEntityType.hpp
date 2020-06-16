// File Name:     IniEntityType.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

namespace IniRW
{
	enum class IniEntityType
	{
		BlankLine,
		Comment,
		Key,
		Section,
		UnknownValue
	};
} // End IniRW namespace