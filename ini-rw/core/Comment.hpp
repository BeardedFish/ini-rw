// File Name:     Comment.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	const std::vector<char> INI_COMMENT_PREFIXES = { '#', ';' };

	class Comment
	{
	public:
		Comment() = delete;

		static bool IsComment(const std::string& str);

		static std::string ExtractAndRemoveComment(std::string& value);
	};
}