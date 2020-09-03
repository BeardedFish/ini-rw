// File Name:     Parse.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	std::string ExtractSectionName(const std::string& section);

	std::string ExtractAndRemoveComment(const std::vector<char>& commentPrefixes, std::string& value);
}