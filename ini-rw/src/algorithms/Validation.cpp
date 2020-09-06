// File Name:     Validation.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/algorithms/Parse.hpp"
#include <iostream>

namespace IniRW
{
	bool IsValidIniKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}

	bool IsValidIniSection(const std::vector<char>& commentPrefixes, const std::string& str)
	{
		size_t leadingWhitespaceCount = 0;

		for (const char& ch : str)
		{
			if (!iswspace(ch))
			{
				break;
			}

			leadingWhitespaceCount++;
		}

		if (str.length() > leadingWhitespaceCount)
		{
			if (str[leadingWhitespaceCount] == SECTION_BEGINNING_CHAR)
			{
				const std::string INI_COMMENT = GetComment(commentPrefixes, str);

				return str.substr(0, str.length() - INI_COMMENT.length()).find_first_of(SECTION_ENDING_CHAR) != std::string::npos;
			}
		}

		return false;
	}

	bool EqualsIgnoreCase(const std::string& str1, const std::string& str2)
	{
		if (str1.length() == str2.length())
		{
			for (size_t i = 0; i < str1.length(); i++)
			{
				if (tolower(str1[i]) != tolower(str2[i]))
				{
					return false;
				}
			}

			return true;
		}

		return false;
	}
}