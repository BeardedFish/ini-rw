// File Name:     IniCommentAlgorithms.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	const std::vector<char> INI_COMMENT_PREFIXES = { '#', ';' };

	bool IsValidIniComment(const std::string& str);

	std::string ExtractAndRemoveComment(std::string& value);
}