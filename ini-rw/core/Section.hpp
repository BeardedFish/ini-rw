// File Name:     Section.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include <string>

namespace IniRW
{
	class Section
	{
	public:
		Section() = delete;
		
		static bool IsSection(const std::string& str);

		static std::string ExtractSectionName(const std::string& section);
	};
}