// File Name:     Search.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "../entities/IniEntity.hpp"
#include "../entities/IniKey.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	/// <summary>
	/// The value the GetSectionLocation() function returns when it can't find the specified INI section. This value is overflowed on purpose.
	/// </summary>
	constexpr size_t SECTION_NOT_FOUND = -1;

	/// <summary>
	/// Searches for an INI key in a vector of type IniEntity* and returns a pointer to the object if found.
	/// </summary>
	/// <param name="iniContents">The vector to be searched.</param>
	/// <param name="sectionName">The name of the INI section the key is attached to.</param>
	/// <param name="keyName">The name of the INI key to be searched for.</param>
	/// <returns>If the key is found in the vector, then a pointer to the INI key is returned. If the key is not found, then a null pointer is returned.</returns>
	IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName);

	/// <summary>
	/// Searches for an INI section in a vector of type IniEntity* and returns the index location if found.
	/// </summary>
	/// <param name="iniContents">The vector to be searched.</param>
	/// <param name="sectionName">The name of the INI section to be searched for.</param>
	/// <returns>
	/// If the INI section is found, then a value >= 0 is returned. The value represents the index location in the vector. If the INI section is not found, then the value
	/// defined in the constant expression "SECTION_NOT_FOUND" is returned.
	/// </returns>
	size_t GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName);
}