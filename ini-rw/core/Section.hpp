// File Name:     Section.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, June 15, 2020

#pragma once

#include "IniEntity.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	class Section
	{
	private:
		constexpr static char SECTION_BEGINNING = '[';
		constexpr static char SECTION_ENDING = ']';

	public:
		static const size_t SECTION_NOT_FOUND = -1;

		Section() = delete;
		
		static bool IsSection(const std::string& str);
		size_t GetSectionLocation(std::vector<IniEntity>& iniContents, const std::string& sectionName);
		
		static std::string ExtractSectionName(const std::string& section);
		static std::string GetFormatted(const std::string& name);
	};
}