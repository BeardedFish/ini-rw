// File Name:     Parse.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "../entities/IniKey.hpp"
#include "../entities/IniSection.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	constexpr char SECTION_BEGINNING_CHAR = '[';

	constexpr char SECTION_ENDING_CHAR = ']';

	const std::vector<char> INI_COMMENT_PREFIXES = { static_cast<char>(IniCommentPrefix::Pound), static_cast<char>(IniCommentPrefix::Semicolon) };

	std::string GetComment(const std::string& value);

	char GetCommentPrefix(const std::string& str);

	std::string GetCommentText(const std::string& str);

	std::string GetStringBeforeComment(const std::string& str);

	IniSection* ParseIniSection(const std::string& iniLine);

	IniKey* ParseIniKey(const std::string& sectionName, const std::string& iniLine);
}