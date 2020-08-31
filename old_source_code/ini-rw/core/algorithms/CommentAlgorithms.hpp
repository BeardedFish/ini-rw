// File Name:     CommentAlgorithms.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 16, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	const std::vector<char> INI_COMMENT_PREFIXES = { '#', ';' };

	/**
	 * Function Name:     IsComment()
	 *
	 * Brief:             Checks whether a string is a valid INI comment or not. A valid INI comment begins with any character defined in the INI_COMMENT_PREFIXES
	 *                    vector.
	 *
	 * Parameters:        str - The string to be checked on whether it is a valid comment or not.
	 *
	 * Return:            True if the string is a valid comment, if not, false.
	 */
	bool IsComment(const std::string& str);

	/**
	 * Function Name:     ExtractAndRemoveComment()
	 * 
	 * Brief:             Searches a string for an INI comment and if it finds one, it extracts it and removes it from the INI value string. A valid INI comment begins
	 *                    with any character defined in the INI_COMMENT_PREFIXES vector. Escaped comments are ignored (ex: "\#" [excluding quotes]).
	 * 
	 * Parameters:        str - The value to be parsed and modified.
	 * 
	 * Return:            If a comment existed in the value, then a string containing the extracted comment is returned. If no comment exists in the value, then an
	 *                    empty string is returned.
	 */
	std::string ExtractAndRemoveComment(std::string& value);
} // End IniRW namespace