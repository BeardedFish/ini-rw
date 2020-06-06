// File Name:     cmdfns.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 6, 2020

#include "cmdfns.hpp"
#include <sstream>

std::vector<std::string> getStrTokens(std::string& str)
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