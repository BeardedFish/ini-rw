// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniKey.hpp"

namespace IniRW
{
	IniKey::IniKey(const std::string& section, const std::string& name, const std::string& value, const std::string& comment) : IniEntity(IniEntityType::Key)
	{
		this->section = section;
		this->name = name;
		this->value = value;
		this->comment = comment;
	}

	std::string IniKey::GetSection() const
	{
		return section;
	}

	std::string IniKey::GetName() const
	{
		return name;
	}

	std::string IniKey::GetValue() const
	{
		return value;
	}

	std::string IniKey::GetComment() const
	{
		return comment;
	}
}