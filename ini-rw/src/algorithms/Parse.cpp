// File Name:     Parse.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Parse.hpp"
#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/enums/IniCommentPrefix.hpp"
#include <iostream>

namespace IniRW
{
	std::string GetComment(const std::vector<char>& commentPrefixes, const std::string& value)
	{
		std::string comment;

		if (value.length() > 0)
		{
			for (size_t i = 0; i < value.length(); i++)
			{
				for (size_t j = 0; j < commentPrefixes.size(); j++)
				{
					if (value[i] == commentPrefixes[j])
					{
						if (i > 0 && value[i - 1] == '\\')
						{
							continue;
						}

						// Extract the comment
						comment = value.substr(i, value.length());

						// Break out of the nested for loop
						i = j = value.length();
					}
				}
			}
		}

		return comment;
	}

	std::string ExtractSectionName(const std::string& section)
	{
		if (!IsValidIniSection(section))
		{
			return section;
		}

		return section.substr(1, section.length() - 2);
	}

	std::string GetStringBeforeComment(const std::vector<char>& commentPrefixes, const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(commentPrefixes, str);

		if (str == "World")
		{
			std::cout << "hi";
		}

		if (str.length() > INI_COMMENT.length())
		{
			return str.substr(0, (str.length() - INI_COMMENT.length()));
		}

		return "";
	}

	char GetCommentPrefix(const std::vector<char>& commentPrefixes, const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(commentPrefixes, str);

		if (!INI_COMMENT.empty())
		{
			return INI_COMMENT[0];
		}

		return '\0';
	}

	std::string GetCommentText(const std::vector<char>& commentPrefixes, const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(commentPrefixes, str);

		if (!INI_COMMENT.empty())
		{
			if (INI_COMMENT.length() > 1)
			{
				return INI_COMMENT.substr(1, INI_COMMENT.length() - 1);
			}
		}

		return str;
	}
}