// File Name:     Parse.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	/// <summary>
	/// Extracts the section name from an INI section by ignoring the leading [ and ending ] and extracting the string in between these two characters.
	/// </summary>
	/// <param name="section">The string that contains the formatted INI section.</param>
	/// <returns>
	/// If the string is a valid INI section, then the extracted INI section name is returned. If it is not a valid section, then the original string is returned.
	/// </returns>
	std::string ExtractSectionName(const std::string& section);

	/// <summary>
	/// Searches a string for an INI comment and if it finds one, it extracts it and removes it from the INI value string. A valid INI comment begins with any character
	/// defined in the "commentPrefixes" vector. Escaped comments (ex: \# or \;) are ignored.
	/// </summary>
	/// <param name="commentPrefixes">A vector of type char which contains all the valid INI comment prefixes.</param>
	/// <param name="value">The string to be modified and parsed.</param>
	/// <returns>
	/// If a comment exists in the value, then a string containing the extracted comment is returned. If no comment exists in the value, then an empty string is returned.
	/// </returns>
	std::string GetComment(const std::vector<char>& commentPrefixes, const std::string& value);

	std::string GetStringBeforeComment(const std::vector<char>& commentPrefixes, const std::string& str);

	char GetCommentPrefix(const std::vector<char>& commentPrefixes, const std::string& str);


	std::string GetCommentText(const std::vector<char>& commentPrefixes, const std::string& str);
}