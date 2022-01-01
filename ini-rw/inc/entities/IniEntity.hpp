// File Name:     IniEntity.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../enums/IniEntityType.hpp"
#include <string>

namespace IniRW
{
	class IniEntity
	{
	public:
		virtual IniEntityType GetType() const = 0;
		virtual std::string ToString() const = 0;
	};
}
