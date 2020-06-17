// File Name:     SectionAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include "../IniEntity.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	constexpr char SECTION_BEGINNING = '[';
	constexpr char SECTION_ENDING = ']';
	constexpr size_t SECTION_NOT_FOUND = -1; // NOTE: You may be thinking that size_t can't hold negative values and you are correct. I'm overflowing this value on purpose.

	/**
	 * Function Name:     IsSection()
	 * 
	 * Brief:             Checks whether a string is a valid INI section or not. A valid INI section begins with "[" and ends with "]" (excluding quotes).
	 * 
	 * Parameters:        str - The string to be checked on whether it is a valid INI section or not.
	 * 
	 * Return:            True if the string is a valid INI section, if not, false.
	 */
	bool IsSection(const std::string& str);

	/**
	 * Function Name:     GetSectionLocation()
	 * 
	 * Brief:             Gets the index location of where an INI section is located in a vector of IniEntity objects.
	 * 
	 * Parameters:        iniContents - The vector which contains the IniEntity objects which represent an INI file.
	 *                    sectionName - The name of the section to be searched for in the vector of IniEntity objects.
	 * 
	 * Return:            If the section is found, then an index >= 0 is returned, this index corresponds to where the section is located in the vector. If the section
	 *                    is not found, then the constant SECTION_NOT_FOUND is returned.
	 */
	size_t GetSectionLocation(std::vector<IniEntity>& iniContents, const std::string& sectionName);

	/**
	 * Function Name:     ExtractSectionName()
	 * 
	 * Brief:             Extracts the section name from an INI section by ignoring the leading [ and ending ] and extracting the string inbetween these two characters.
	 *  
	 * Parameters:        iniContents - The vector which contains the IniEntity objects which represent an INI file.
	 *                    sectionName - The name of the section to be searched for in the vector of IniEntity objects.
	 *
	 * Return:            If the string is a valid INI section, then the extracted INI section name is returned. If it is not a valid section, then the original string
	 *                    is returned.
	 */
	std::string ExtractSectionName(const std::string& section);

	/**
	 * Function Name:     GetFormattedSectionName()
	 * 
	 * Brief:             Formats a string to INI section format. An INI section format begins with [ and ends with ].
	 * 
	 * Parameters:        name - The name of the section to be converted to INI section format.
	 * 
	 * Return:            A string that is formatted.
	 */
	std::string GetFormattedSectionName(const std::string& name);
} // End IniRW namespace