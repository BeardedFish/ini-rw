// File Name:     Search.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "../entities/IniEntity.hpp"
#include "../entities/IniKey.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	/// <summary>
	/// The value the GetSectionLocation() function returns when it can't find the specified INI section. This value is overflowed on purpose.
	/// </summary>
	constexpr size_t SECTION_NOT_FOUND = -1;

	size_t GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName);

	IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName);
}