// File Name:     InputFns.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../includes/InputFns.hpp"
#include <iostream>
#include <sstream>

std::vector<std::string> GetTokenizedInput()
{
	std::string userInput;
	std::getline(std::cin, userInput);

	std::vector<std::string> tokens;
	std::istringstream strStream(userInput);
	std::string currentToken;

	while (strStream >> currentToken)
	{
		tokens.push_back(currentToken);
	}

	return tokens;
}