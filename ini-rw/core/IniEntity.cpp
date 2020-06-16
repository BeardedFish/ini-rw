// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#include "IniEntity.hpp"
#include <string>

namespace IniRW
{
	IniEntity::IniEntity()
	{
		this->type = IniEntityType::UnknownValue;
		this->data = nullptr;
	}

	IniEntity::IniEntity(IniEntityType type) : IniEntity()
	{
		this->type = type;
	}

	IniEntity::IniEntity(IniEntityType type, void* data)
	{
		this->type = type;
		this->data = data;
	}

	void* IniEntity::GetData()
	{
		if (type == IniEntityType::BlankLine)
		{
			return nullptr;
		}

		return data;
	}

	IniEntityType IniEntity::GetType()
	{
		return type;
	}
}