// File Name:     IniEntity.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../enums/IniEntityType.hpp"
#include <string>

namespace IniRW
{
	class IniEntity
	{
	public:
		/// <summary>
		/// Abstract function to be implemented in a derived class. On implementation, this function is supposed to tell a user what kind of INI entity the subclass is.
		/// </summary>
		/// <returns>Return value will vary on the derived classes.</returns>
		virtual IniEntityType GetType() = 0;

		/// <summary>
		/// Abstract function to be implemented in a derived class. On implementation, this function is supposed to give a string representation of an INI entity.
		/// </summary>
		/// <returns>Return value will vary on the derived classes.</returns>
		virtual std::string ToString() const = 0;
	};
}