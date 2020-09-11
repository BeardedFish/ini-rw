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
	/// <summary>
	/// The character that an INI section must begin with.
	/// </summary>
	constexpr char INI_BEGINNING_CHAR = '[';

	/// <summary>
	/// The character that an INI section must end with.
	/// </summary>
	constexpr char INI_SECTION_ENDING = ']';

	/// <summary>
	/// The character that separates the name and value of an INI key.
	/// </summary>
	constexpr char INI_KEY_VALUE_DELIMITER = '=';

	/// <summary>
	/// A C-string which contains all whitespace characters.
	/// </summary>
	constexpr char WHITESPACE_CHARACTERS[] = " \f\n\r\t\v";

	/// <summary>
	/// A vector which contains all the valid INI comment prefix characters.
	/// </summary>
	const std::vector<char> INI_COMMENT_PREFIXES =
	{
		static_cast<char>(IniCommentPrefix::Pound),
		static_cast<char>(IniCommentPrefix::Semicolon)
	};

	/// <summary>
	/// Searches for an INI comment in a string. If an INI comment is found, it is extracted into a new string. This function ignores escaped comments.
	/// </summary>
	/// <param name="str">The string to be parsed.</param>
	/// <returns>
	/// If the string contains an INI comment, then a string containing the comment is returned. This string also included the INI comment prefix. If the string does not
	/// contains an INI comment, then an empty string is returned.
	/// </returns>
	std::string ExtractIniComment(const std::string& str);

	/// <summary>
	/// Trims leading whitespace on a string.
	/// </summary>
	/// <param name="str">The string to be trimmed.</param>
	/// <returns>A string without leading whitespace.</returns>
	std::string LeftTrim(const std::string& str);

	/// <summary>
	/// Trims trailing whitespace on a string.
	/// </summary>
	/// <param name="str">The string to be trimmed.</param>
	/// <returns>A string without trailing whitespace.</returns>
	std::string RightTrim(const std::string& str);

	/// <summary>
	/// Tries to parse a line from an INI file into an INI section object.
	/// </summary>
	/// <param name="iniLine">The line from an INI file to be parsed.</param>
	/// <returns>If the parse was successful, an IniSection pointer is returned. If the parse was not successful, then a null pointer is returned.</returns>
	IniSection* ParseIniSection(const std::string& iniLine);

	/// <summary>
	/// Tries to parse a line from an INI file into an INI key object.
	/// </summary>
	/// <param name="sectionName">The name of the section the INI key will belong to if the parse is successful.</param>
	/// <param name="iniLine">The line from an INI file to be parsed.</param>
	/// <returns>If the parse was successful, an IniKey pointer is returned. If the parse was not successful, then a null pointer is returned.</returns>
	IniKey* ParseIniKey(const std::string& sectionName, const std::string& iniLine);

	/// <summary>
	/// Trims leading and trailing whitespace on a string.
	/// </summary>
	/// <param name="str">The string to be trimmed.</param>
	/// <returns>A string without leading or trailing whitespace.</returns>
	std::string Trim(const std::string& str);
}