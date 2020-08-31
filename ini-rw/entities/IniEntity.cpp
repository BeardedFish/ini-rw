// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniEntity.hpp"

namespace IniRW
{
	IniEntity::IniEntity(const IniEntityType& type)
	{
		this->type = type;
	}

	IniEntityType IniEntity::GetType() const
	{
		return type;
	}
}