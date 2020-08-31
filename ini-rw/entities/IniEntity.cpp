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

	IniEntity::IniEntity(const IniStringType& type)
	{
		if (type == IniStringType::Comment)
		{
			this->type = IniEntityType::Comment;
		}
		else if (type == IniStringType::NewLine)
		{
			this->type = IniEntityType::NewLine;
		}
		else if (type == IniStringType::Section)
		{
			this->type = IniEntityType::Section;
		}
		else // Unknown value
		{
			this->type = IniEntityType::UnknownValue;
		}
	}

	IniEntityType IniEntity::GetType() const
	{
		return type;
	}
}