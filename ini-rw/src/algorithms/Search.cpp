// File Name:     Search.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../include/algorithms/Search.hpp"
#include "../../include/algorithms/Validation.hpp"
#include "../../include/entities/IniSection.hpp"

size_t inirw::find_ini_key_index(std::vector<IniEntity*>& iniContents, const std::string& keyName, const bool& isKeyGlobal)
{
	for (size_t i = 0; i < iniContents.size(); i++)
	{
		if (iniContents[i]->get_type() != IniEntityType::Key)
		{
			continue;
		}

		IniKey* key = static_cast<IniKey*>(iniContents[i]);

		if (isKeyGlobal && key->get_section())
		{
			continue;
		}

		if (equals_ignore_case(key->get_name(), keyName))
		{
			return i;
		}
	}

	return INI_NOT_FOUND;
}

size_t inirw::find_ini_key_index(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName)
{
	for (size_t i = 0; i < iniContents.size(); i++)
	{
		if (iniContents[i]->get_type() != IniEntityType::Key)
		{
			continue;
		}

		IniKey* key = static_cast<IniKey*>(iniContents[i]);

		if (equals_ignore_case(key->get_section()->get_name(), sectionName) && equals_ignore_case(key->get_name(), keyName))
		{
			return i;
		}
	}

	return INI_NOT_FOUND;
}

size_t inirw::find_ini_section_index(std::vector<IniEntity*>& iniContents, const std::string& sectionName)
{
	for (size_t i = 0; i < iniContents.size(); i++)
	{
		if (iniContents[i]->get_type() == IniEntityType::Section)
		{
			if (static_cast<IniSection*>(iniContents[i])->get_name() == sectionName)
			{
				return i;
			}
		}
	}

	return INI_NOT_FOUND;
}
