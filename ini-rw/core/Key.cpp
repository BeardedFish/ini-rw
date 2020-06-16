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

	void Key::SetValue(const std::string& newValue)
	{
		value = newValue;
	}

	bool Key::IsKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}
}