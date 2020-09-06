// File Name:     Parse.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	std::string ExtractSectionName(const std::string& section);

	std::string GetComment(const std::vector<char>& commentPrefixes, const std::string& value);

	char GetCommentPrefix(const std::vector<char>& commentPrefixes, const std::string& str);

	std::string GetCommentText(const std::vector<char>& commentPrefixes, const std::string& str);

	std::string GetStringBeforeComment(const std::vector<char>& commentPrefixes, const std::string& str);
}