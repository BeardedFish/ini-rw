// File Name:     InputFns.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include <string>
#include <vector>

/// <summary>
/// Gets the console input from the user via the "std::cin" stream and splits all words by whitespace.
/// </summary>
/// <returns>A vector of type string which contains all the tokens a user typed into the console.</returns>
std::vector<std::string> GetTokenizedInput();

/// <summary>
/// Converts a vector of strings to a string. Each string is separated by a single space character.
/// </summary>
/// <param name="vector">The vector which contains strings.</param>
/// <param name="startIndex">The start index where the conversion should start place in the vector.</param>
/// <returns>A string which contains elements from the "startIndex" to the vector's length - 1.</returns>
std::string VectorToString(std::vector<std::string> vector, size_t startIndex);