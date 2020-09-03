// File Name:     IniNewLine.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniNewLine.hpp"
#include "IniEntity.hpp"

namespace IniRW
{
	class IniNewLine : public IniEntity
	{
	public:
		IniEntityType GetType() override;

		char GetValue() const;
	};
}