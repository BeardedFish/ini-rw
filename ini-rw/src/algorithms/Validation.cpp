// File Name:     Validation.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/algorithms/Parse.hpp"

bool IniRW::EqualsIgnoreCase(const std::string& str1, const std::string& str2)
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