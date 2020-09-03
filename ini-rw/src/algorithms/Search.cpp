// File Name:     Search.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Search.hpp"
#include "../../inc/entities/IniSection.hpp"

namespace IniRW
{
	IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i]->GetType() != IniEntityType::Key)
			{
				continue;
			}

			IniKey* key = static_cast<IniKey*>(iniContents[i]);

			if (_strcmpi(key->GetSection().c_str(), sectionName.c_str()) == 0 
				&& _strcmpi(key->GetName().c_str(), keyName.c_str()) == 0)
			{
				return key;
			}
		}

		return nullptr;
	}

	size_t GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i]->GetType() == IniEntityType::Section)
			{
				if (static_cast<IniSection*>(iniContents[i])->GetName() == sectionName)
				{
					return i;
				}
			}
		}

		return -1;
	}
}