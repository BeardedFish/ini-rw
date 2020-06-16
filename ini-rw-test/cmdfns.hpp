// File Name:     cmdfns.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include "ini-rw/return_types/ReadResult.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getStrTokens(const std::string& str);

template<typename T>
void printResult(IniRW::ReadResult<T> readResult, std::string section, std::string key) // NOTE: Template functions can't have body code in .cpp files so the body code is defined here
{
	if (readResult.Success)
	{
		std::cout << "The extracted value is: " << readResult.ConvertedValue;
	}
	else
	{
		std::cout << "Unable to extract the key \"" << key << "\" value from the section \"" << section << "\".";
	}

	std::cout << std::endl << std::endl;
}