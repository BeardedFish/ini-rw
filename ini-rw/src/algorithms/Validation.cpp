// File Name:     Validation.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Validation.hpp"

namespace IniRW
{
	bool IsValidIniComment(const std::vector<char>& commentPrefixes, const std::string& str)
	{
		if (str.length() >= 1)
		{
			for (const char& prefix : commentPrefixes)
			{
				if (str[0] == prefix)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool IsValidIniKey(const std::string& str)
	{
		return str.length() >= 3 && str.find_first_of('=') != std::string::npos;
	}

	bool IsValidIniSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == SECTION_BEGINNING_CHAR && str[str.length() - 1] == SECTION_ENDING_CHAR;
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