// File Name:     InputFns.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../inc/InputFns.hpp"
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

std::string VectorToString(std::vector<std::string> vector, size_t startIndex)
{
	std::string result = "";

	for (size_t i = startIndex; i < vector.size(); i++)
	{
		result += vector[i] + (i == vector.size() - 1 ? "" : " ");
	}

	return result;
}