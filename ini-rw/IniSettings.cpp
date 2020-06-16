// File Name:     IniSettings.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#include "IniSettings.hpp"

namespace IniRW
{
	IniSettings::IniSettings(const std::string& iniFilePath) : IniFileContents(iniFilePath)
	{
	
	}

	std::string IniSettings::GetKeyValue(const std::string& sectionName, const std::string& keyName)
	{
		Key* key = FindKey(sectionName, keyName);

		if (key != nullptr)
		{
			return key->GetValue();
		}

		return nullptr;
	}

	void IniSettings::WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		Key* key = FindKey(sectionName, keyName);

		if (key != nullptr)
		{
			key->SetValue(keyValue);
		}
	}
}