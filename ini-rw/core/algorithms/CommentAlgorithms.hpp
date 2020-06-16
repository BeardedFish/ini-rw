// File Name:     CommentAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	const std::vector<char> INI_COMMENT_PREFIXES = { '#', ';' };

	bool IsComment(const std::string& str);

	std::string ExtractAndRemoveComment(std::string& value);
} // End IniRW namespace