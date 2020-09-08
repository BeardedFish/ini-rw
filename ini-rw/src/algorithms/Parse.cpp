// File Name:     Parse.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Parse.hpp"
#include "../../inc/algorithms/Sum.hpp"
#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/enums/IniCommentPrefix.hpp"
#include <iostream>

namespace IniRW
{
	std::string GetComment(const std::string& value)
	{
		if (value.length() > 0)
		{
			for (size_t i = 0; i < value.length(); i++)
			{
				for (const char& prefix : INI_COMMENT_PREFIXES)
				{
					if (value[i] == prefix)
					{
						if (i > 0 && value[i - 1] == '\\')
						{
							continue;
						}

						// Extract the comment
						return value.substr(i, value.length());
					}
				}
			}
		}

		return "";
	}

	std::string GetStringBeforeComment(const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(str);

		if (str.length() > INI_COMMENT.length())
		{
			return str.substr(0, (str.length() - INI_COMMENT.length()));
		}

		return "";
	}

	char GetCommentPrefix(const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(str);

		if (!INI_COMMENT.empty())
		{
			return INI_COMMENT[0];
		}

		return '\0';
	}

	std::string GetCommentText(const std::string& str)
	{
		const std::string INI_COMMENT = GetComment(str);

		if (!INI_COMMENT.empty())
		{
			if (INI_COMMENT.length() > 1)
			{
				return INI_COMMENT.substr(1, INI_COMMENT.length() - 1);
			}
		}

		return str;
	}

	IniSection* ParseIniSection(const std::string& str)
	{
		const size_t LEADING_WHITESPACE_COUNT = CountLeadingWhitespace(str);
		IniSection* section = nullptr;

		if (str.length() > LEADING_WHITESPACE_COUNT)
		{
			if (str[LEADING_WHITESPACE_COUNT] == SECTION_BEGINNING_CHAR)
			{
				const std::string INI_COMMENT = GetComment(str);
				const std::string WITHOUT_COMMENT = str.substr(0, str.length() - INI_COMMENT.length());

				if (WITHOUT_COMMENT.find_first_of(SECTION_ENDING_CHAR) != std::string::npos) // It's a valid INI section
				{
					const std::string LEADING_WHITESPACE = str.substr(0, LEADING_WHITESPACE_COUNT);
					const std::string SECTION_NAME = WITHOUT_COMMENT.substr(LEADING_WHITESPACE_COUNT + 1, WITHOUT_COMMENT.find_last_of(SECTION_ENDING_CHAR) - LEADING_WHITESPACE_COUNT - 1);
					const IniValueCommentPair EXTRA_DATA = str.substr(LEADING_WHITESPACE.length() + SECTION_NAME.length() + 2);

					section = new IniSection(LEADING_WHITESPACE, SECTION_NAME, EXTRA_DATA);
				}
			}
		}

		return section;
	}

	IniKey* ParseIniKey(const std::string& sectionName, const std::string& iniLine)
	{
		IniKey* result = nullptr;

		if (iniLine.length() >= 3)
		{
			const size_t EQUAL_SIGN_POS = iniLine.find_first_of('=');

			if (EQUAL_SIGN_POS != std::string::npos)
			{
				std::string keyName = iniLine.substr(0, EQUAL_SIGN_POS);
				std::string keyCommentValue = iniLine.substr(EQUAL_SIGN_POS + 1);

				result = new IniKey(sectionName, keyName, keyCommentValue);
			}
		}

		return result;
	}
}