// File Name:     IniEntity.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../enums/IniEntityType.hpp"
#include "../enums/IniStringType.hpp"

namespace IniRW
{
	class IniEntity
	{
	private:
		IniEntityType type;

	public:
		IniEntity(const IniEntityType& type);

		IniEntity(const IniStringType& type);

		IniEntityType GetType() const;
	};
}