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
		virtual IniEntityType get_type() const = 0;
		virtual std::string to_string() const = 0;
	};
}
