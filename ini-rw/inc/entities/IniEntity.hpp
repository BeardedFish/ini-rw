// File Name:     IniEntity.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../enums/IniEntityType.hpp"

namespace IniRW
{
	class IniEntity
	{
	public:
		/// <summary>
		/// Abstract function to be implemented in subclasses. This function is supposed to tell a user what kind of INI entity the subclass is.
		/// </summary>
		/// <returns>Return value will depend on the subclass.</returns>
		virtual IniEntityType GetType() = 0;
	};
}