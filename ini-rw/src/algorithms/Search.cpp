// File Name:     Search.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Search.hpp"
#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/entities/IniSection.hpp"

size_t IniRW::FindKeyIndex(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName)
{
	for (size_t i = 0; i < iniContents.size(); i++)
	{
		if (iniContents[i]->GetType() != IniEntityType::Key)
		{
			continue;
		}

		IniKey* key = static_cast<IniKey*>(iniContents[i]);

		if (EqualsIgnoreCase(key->GetSection()->GetName(), sectionName) && EqualsIgnoreCase(key->GetName(), keyName))
		{
			return i;
		}
	}

	return INI_NOT_FOUND;
}

size_t IniRW::GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName)
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

	return INI_NOT_FOUND;
}