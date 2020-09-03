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
	/// Gets the index location of where an INI section is located in a vector of type IniEntity pointer objects.
	/// </summary>
	/// <param name="iniContents">The vector which contains the contents of an INI file.</param>
	/// <param name="sectionName">The name of the section to be searched for in the vector.</param>
	/// <returns>
	/// If the section is found, then an index >= 0 is returned, this index corresponds to where the section is located in the vector. If the section is not found, then the
	/// value defined in the SECTION_NOT_FOUND constant variable is returned.
	/// </returns>
	size_t GetSectionLocation(std::vector<IniEntity*>& iniContents, const std::string& sectionName);

	/// <summary>
	/// Searches a vector of type IniEntity pointer objects for a specific INI key.
	/// </summary>
	/// <param name="iniContents">The vector which contains the contents of an INI file.</param>
	/// <param name="sectionName">The name of the section to .</param>
	/// <param name="keyName">The name of the key to be searched for.</param>
	/// <returns>If the key is found, then a pointer to that IniKey object is returned. If the key is not found, then null pointer is returned.</returns>
	IniKey* FindKey(std::vector<IniEntity*>& iniContents, const std::string& sectionName, const std::string& keyName);
}