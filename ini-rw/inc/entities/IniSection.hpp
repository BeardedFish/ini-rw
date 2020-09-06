// File Name:     IniSection.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniEntity.hpp"
#include <string>

namespace IniRW
{
	class IniSection : public IniEntity
	{
	private:
		std::string name;

	public:
		/// <summary>
		/// Constructor for creating an INI section.
		/// </summary>
		/// <param name="name">The name of the INI section. This value should exclude the "[" and "]" characters (excluding quotes).</param>
		IniSection(const std::string& name);

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::Section.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Returns the string representation of this INI section.
		/// </summary>
		/// <returns>A string in the format: "[INI_SECTION_NAME]" (excluding quotes).</returns>
		std::string ToString() const override;

		/// <summary>
		/// Gets the name of this INI section in a formatted manner.
		/// </summary>
		/// <returns>A string in the format: "[INI_SECTION_NAME]" (excluding quotes).</returns>
		std::string GetName() const;
	};
}