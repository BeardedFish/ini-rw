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
	std::string GetComment(const std::vector<char>& commentPrefixes, const std::string& value);

	char GetCommentPrefix(const std::vector<char>& commentPrefixes, const std::string& str);

	std::string GetCommentText(const std::vector<char>& commentPrefixes, const std::string& str);

	std::string GetStringBeforeComment(const std::vector<char>& commentPrefixes, const std::string& str);

	IniSection* ParseIniSection(const std::vector<char>& commentPrefixes, const std::string& iniLine);

	IniKey* ParseIniKey(const std::vector<char>& commentPrefixes, const std::string& sectionName, const std::string& iniLine);
}