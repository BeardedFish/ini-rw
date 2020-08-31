// File Name:     IniKeyAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "../IniKey.hpp"
#include <string>
#include <VECTOR>

namespace IniRW
{
	bool IsValidIniKey(const std::string& str);

	// IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName);

}