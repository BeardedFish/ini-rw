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
	constexpr char INI_BEGINNING_CHAR = '[';

	constexpr char INI_SECTION_ENDING = ']';

	constexpr char INI_KEY_VALUE_DELIMITER = '=';

	constexpr char WHITESPACE_CHARACTERS[] = " \f\n\r\t\v";

	const std::vector<char> INI_COMMENT_PREFIXES = { static_cast<char>(IniCommentPrefix::Pound), static_cast<char>(IniCommentPrefix::Semicolon) };

	std::string GetComment(const std::string& value);

	char GetCommentPrefix(const std::string& str);

	std::string GetCommentText(const std::string& str);

	std::string GetStringBeforeComment(const std::string& str);

	IniSection* ParseIniSection(const std::string& iniLine);

	IniKey* ParseIniKey(const std::string& sectionName, const std::string& iniLine);

	std::string LeftTrim(const std::string& str);

	std::string RightTrim(const std::string& str);

	std::string Trim(const std::string& str);
}