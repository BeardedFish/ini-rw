// File Name:     KeyAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#include "KeyAlgorithms.hpp"

namespace IniRW
{
	bool IsKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}

	Key* FindKey(std::vector<IniEntity>& iniContents, const std::string& sectionName, const std::string& keyName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i].GetType() == IniEntityType::Key)
			{
				Key* key = static_cast<Key*>(iniContents[i].GetData());

				if (LowercaseValue(key->GetSection()) == LowercaseValue(sectionName)
					&& LowercaseValue(key->GetName()) == LowercaseValue(keyName))
				{
					return key;
				}
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
} // End IniRW namespace