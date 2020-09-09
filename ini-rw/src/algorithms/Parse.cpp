// File Name:     Parse.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Parse.hpp"
#include "../../inc/algorithms/Validation.hpp"
#include "../../inc/enums/IniCommentPrefix.hpp"

std::string IniRW::GetComment(const std::string& value)
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

std::string IniRW::GetStringBeforeComment(const std::string& str)
{
	const std::string INI_COMMENT = GetComment(str);

	if (str.length() > INI_COMMENT.length())
	{
		return str.substr(0, (str.length() - INI_COMMENT.length()));
	}

	return "";
}

char IniRW::GetCommentPrefix(const std::string& str)
{
	const std::string INI_COMMENT = GetComment(str);

	if (!INI_COMMENT.empty())
	{
		return INI_COMMENT[0];
	}

	return '\0';
}

std::string IniRW::GetCommentText(const std::string& str)
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

IniRW::IniSection* IniRW::ParseIniSection(const std::string& str)
{
	const size_t LEADING_WHITESPACE_COUNT = str.find_first_not_of(WHITESPACE_CHARACTERS);

	if (str.length() > LEADING_WHITESPACE_COUNT)
	{
		if (str[LEADING_WHITESPACE_COUNT] == INI_BEGINNING_CHAR)
		{
			const std::string INI_COMMENT = GetComment(str);
			const std::string WITHOUT_COMMENT = str.substr(0, str.length() - INI_COMMENT.length());

			if (WITHOUT_COMMENT.find_first_of(INI_SECTION_ENDING) != std::string::npos) // It's a valid INI section
			{
				const std::string LEADING_WHITESPACE = str.substr(0, LEADING_WHITESPACE_COUNT);
				const std::string SECTION_NAME = WITHOUT_COMMENT.substr(LEADING_WHITESPACE_COUNT + 1, WITHOUT_COMMENT.find_last_of(INI_SECTION_ENDING) - LEADING_WHITESPACE_COUNT - 1);
				const IniValueCommentPair EXTRA_DATA = str.substr(LEADING_WHITESPACE.length() + SECTION_NAME.length() + 2);

				return new IniSection(LEADING_WHITESPACE, SECTION_NAME, EXTRA_DATA);
			}
		}
	}

	return nullptr;
}

IniRW::IniKey* IniRW::ParseIniKey(const std::string& sectionName, const std::string& iniLine)
{
	if (iniLine.length() >= 3)
	{
		const size_t EQUAL_SIGN_POS = iniLine.find_first_of(INI_KEY_VALUE_DELIMITER);

		if (EQUAL_SIGN_POS != std::string::npos)
		{
			const std::string KEY_NAME = iniLine.substr(0, EQUAL_SIGN_POS);
			const IniValueCommentPair VALUE_COMMENT_PAIR = iniLine.substr(EQUAL_SIGN_POS + 1);

			return new IniKey(sectionName, KEY_NAME, VALUE_COMMENT_PAIR);
		}
	}

	return nullptr;
}