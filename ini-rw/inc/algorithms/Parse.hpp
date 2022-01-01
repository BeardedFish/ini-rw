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
	constexpr char INI_SECTION_BEGINNING = '[';
	constexpr char INI_SECTION_ENDING = ']';
	constexpr char INI_KEY_VALUE_DELIMITER = '=';
	constexpr char WHITESPACE_CHARACTERS[] = " \f\n\r\t\v";

	const std::vector<char> INI_COMMENT_PREFIXES =
	{
		static_cast<char>(IniCommentPrefix::Pound),
		static_cast<char>(IniCommentPrefix::Semicolon)
	};

	std::string extract_ini_comment(const std::string& str);

	std::string left_trim(const std::string& str);

	std::string right_trim(const std::string& str);

	IniSection* parse_ini_section(const std::string& iniLine);

	IniKey* parse_ini_key(IniSection* iniSection, const std::string& iniLine);

	std::string trim(const std::string& str);
}
