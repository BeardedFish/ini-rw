// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../inc/entities/IniKey.hpp"

namespace IniRW
{
	IniKey::IniKey(const std::string& section, const std::string& name, const std::string& value, const std::string& comment) : IniEntity()
	{
		this->section = section;
		this->name = name;
		this->value = value;
		this->comment = comment;
	}

	IniEntityType IniKey::GetType()
	{
		return IniEntityType::Key;
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

	void IniKey::SetValue(const std::string& newValue)
	{
		value = newValue;
	}
}