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
		/// Returns the new line character.
		/// </summary>
		/// <returns>The new line character: "\n".</returns>
		char GetValue() const;
	};
}