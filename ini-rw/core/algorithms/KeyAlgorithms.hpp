// File Name:     KeyAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include "../IniEntity.hpp"
#include "../Key.hpp"
#include <string>

namespace IniRW
{
	bool IsKey(const std::string& str);
	Key* FindKey(std::vector<IniEntity>& iniContents, const std::string& sectionName, const std::string& keyName);

	std::string LowercaseValue(const std::string& str);
} // End IniRW namespace