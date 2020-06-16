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

	bool Key::IsKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}

	Key* Key::FindKey(std::vector<IniEntity>& iniContents, const std::string& sectionName, const std::string& keyName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i].GetType() == IniEntityType::Key)
			{
				Key* key = static_cast<Key*>(iniContents[i].GetData());

				if (getLowercaseStr(key->GetSection()) == getLowercaseStr(sectionName)
					&& getLowercaseStr(key->GetName()) == getLowercaseStr(keyName))
				{
					return key;
				}
			}
		}

		return nullptr;
	}

	std::string Key::getLowercaseStr(const std::string& str)
	{
		std::string lowerStr;

		for (size_t i = 0; i < str.length(); i++)
		{
			lowerStr += tolower(str[i]);
		}

		return lowerStr;
	}
}