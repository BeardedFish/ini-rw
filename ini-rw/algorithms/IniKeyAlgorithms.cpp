// File Name:     IniKeyAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniKeyAlgorithms.hpp"

namespace IniRW
{
	bool IsValidIniKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}

	IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i]->GetType() != IniEntityType::Key)
			{
				continue;
			}

			IniKey* key = static_cast<IniKey*>(iniContents[i]);

			if (LowercaseValue(key->GetSection()) == LowercaseValue(sectionName) && LowercaseValue(key->GetName()) == LowercaseValue(keyName))
			{
				return key;
			}
		}

		return nullptr;
	}

	std::string LowercaseValue(const std::string& str)
	{
		std::string lowerStr;

		for (size_t i = 0; i < str.length(); i++)
		{
			lowerStr += tolower(str[i]);
		}

		return lowerStr;
	}
}