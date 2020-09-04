// File Name:     IniNewLine.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniNewLine.hpp"
#include "IniEntity.hpp"

namespace IniRW
{
	class IniNewLine : public IniEntity
	{
	public:
		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::NewLine.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Returns the string representation of this INI new line entity.
		/// </summary>
		/// <returns>A string that contains the newline character, "\n" (excluding quotes).</returns>
		std::string ToString() const override;
	};
}