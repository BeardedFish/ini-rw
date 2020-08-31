// File Name:     IniCommentAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "IniCommentAlgorithms.hpp"
#include <string>

namespace IniRW
{
	bool IsValidIniComment(const std::string& str)
	{
		if (str.length() >= 1)
		{
			for (size_t i = 0; i < INI_COMMENT_PREFIXES.size(); i++)
			{
				if (str[0] == INI_COMMENT_PREFIXES[i])
				{
					return true;
				}
			}
		}

		return false;
	}

	std::string ExtractAndRemoveComment(std::string& value)
	{
		std::string comment;

		for (size_t i = 0; i < value.length() - 1; i++)
		{
			for (size_t j = 0; j < INI_COMMENT_PREFIXES.size(); j++)
			{
				if (value[i] != '\\' && value[i + 1] == INI_COMMENT_PREFIXES[j]) // Found the comment
				{
					// Extract the comment
					comment = value.substr(i, value.length() - 1);

					// Remove the comment from the original value
					value = value.substr(0, i);

					// Break out of the nested for loop
					i = j = value.length();
				}
			}
		}

		return comment;
	}
}