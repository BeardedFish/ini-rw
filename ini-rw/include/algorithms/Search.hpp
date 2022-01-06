// File Name:     Search.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "../entities/IniEntity.hpp"
#include "../entities/IniKey.hpp"
#include <limits>
#include <string>
#include <vector>

namespace inirw
{
	constexpr size_t INI_NOT_FOUND = std::numeric_limits<size_t>::max();

	size_t find_key_index(std::vector<IniEntity*>& iniContents, const std::string& keyName, const bool& isKeyGlobal);

	size_t find_key_index(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName);

	size_t get_section_location(std::vector<IniEntity*>& iniContents, const std::string& sectionName);
}
