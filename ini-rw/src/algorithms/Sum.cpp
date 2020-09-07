// File Name:     Sum.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, September 6, 2020

#include "../../inc/algorithms/Sum.hpp"

namespace IniRW
{
	size_t CountLeadingWhitespace(const std::string& str)
	{
		size_t total = 0;

		for (const char& ch : str)
		{
			if (!iswspace(ch))
			{
				break;
			}

			total++;
		}

		return total;
	}
}