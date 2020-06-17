// File Name:     KeyAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include "../IniEntity.hpp"
#include "../Key.hpp"
#include <string>

namespace IniRW
{
	/**
	 * Function Name:     IsKey()
	 *
	 * Brief:             Checks whether a string is a valid INI key or not. A valid INI key has the format: "KEY_NAME=KEY_VALUE" (excluding quotes). A valid key must
	 *                    also be at minimum 3 characters in length.
	 *
	 * Parameters:        str - The string to be checked on whether it is a valid key or not.
	 *
	 * Return:            True if the string is a valid key, if not, false.
	 */
	bool IsKey(const std::string& str);

	/**
	 * Function Name:     FindKey()
	 *
	 * Brief:             Searches a vector of type IniEntity for a specific key.
	 *
	 * Parameters:        iniContents - The vector which contains the IniEntity objects which represent an INI file.
	 *                    sectionName - The name of the section which the key belongs to.
	 *                    keyName - The name of the key to be searched for.
	 *
	 * Return:            If the key is found, then a pointer to that Key object is returned. If the key is not found, then null pointer is returned.
	 */
	Key* FindKey(std::vector<IniEntity>& iniContents, const std::string& sectionName, const std::string& keyName);

	/**
	 * Function Name:     LowercaseValue()
	 *
	 * Brief:             Converts a string to lowercase.
	 *
	 * Parameters:        str - The string to be converted to lowercase.
	 *
	 * Return:            A string that is a lowercase version of the one passed in the parameter of the function.
	 */
	std::string LowercaseValue(const std::string& str);
} // End IniRW namespace