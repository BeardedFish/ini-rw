// File Name:     Key.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#include "Key.hpp"

namespace IniRW
{
	Key::Key(const std::string& section, const std::string& name, const std::string& value)
	{
		this->section = section;
		this->name = name;
		this->value = value;
		this->comment = "";
	}

	Key::Key(const std::string& section, const std::string& name, const std::string& value, const std::string& comment)
	{
		this->section = section;
		this->name = name;
		this->value = value;
		this->comment = comment;
	}

	std::string Key::GetSection()
	{
		return section;
	}

	std::string Key::GetName()
	{
		return name;
	}

	std::string Key::GetValue()
	{
		return value;
	}

	std::string Key::GetComment()
	{
		return comment;
	}

	void Key::SetValue(const std::string& newValue)
	{
		value = newValue;
	}
} // End IniRW namespace