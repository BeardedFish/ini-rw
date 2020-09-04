// File Name:     IniString.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#pragma once

#include "IniEntity.hpp"

namespace IniRW
{
	class IniString : public IniEntity
	{
	private:
		std::string value;

	public:
		/// <summary>
		/// Holds a string in an INI file.
		/// </summary>
		/// <param name="value">The value that this INI string will hold.</param>
		IniString(const std::string& value);

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::String.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Returns the string value that is held in this INI string instance.
		/// </summary>
		/// <returns>A string. The exact value will vary.</returns>
		std::string ToString() const override;
	};
}