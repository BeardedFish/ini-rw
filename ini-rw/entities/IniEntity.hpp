// File Name:     IniEntity.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../enums/IniEntityType.hpp"

namespace IniRW
{
	class IniEntity
	{
	public:
		virtual IniEntityType GetType() = 0;
	};
}