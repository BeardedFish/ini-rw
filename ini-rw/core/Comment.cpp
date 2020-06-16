// File Name:     Comment.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#include "Comment.hpp"
#include <vector>

namespace IniRW
{
	bool Comment::IsComment(const std::string& str)
	{
		const std::vector<char> COMMENT_PREFIXES = { '#', ';' };

		if (str.length() >= 1)
		{
			for (size_t i = 0; i < COMMENT_PREFIXES.size(); i++)
			{
				if (str[0] == COMMENT_PREFIXES[i])
				{
					return true;
				}
			}
		}

		return false;
	}
}