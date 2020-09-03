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
		IniSection(const std::string& name);

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The return value will always be IniEntityType::Section.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		std::string GetName();
	};
}