// File Name:     cmdfns.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#include "cmdfns.hpp"
#include <sstream>

std::vector<std::string> getStrTokens(const std::string& str)
{
	std::istringstream strStream(str);
	std::vector<std::string> result;

	std::string token;
	while (strStream >> token)
	{
		result.push_back(token);
	}

	return result;
}