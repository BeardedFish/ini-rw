// File Name:     IniValueCommentPair.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#include "../../include/entities/IniValueCommentPair.hpp"
#include "../../include/algorithms/Parse.hpp"
#include <iostream>

namespace inirw
{
	IniValueCommentPair::IniValueCommentPair() : IniValueCommentPair("", '\0', "")
	{

	}

	IniValueCommentPair::IniValueCommentPair(const std::string& data)
		: IniValueCommentPair(extract_value(data), extract_comment_prefix(data), extract_comment_text(data))
	{

	}

	IniValueCommentPair::IniValueCommentPair(const std::string& value, const char& commentPrefix, const std::string& commentText)
		: m_value(value), m_commentPrefix(commentPrefix), m_commentText(commentText)
	{

	}

	IniEntityType IniValueCommentPair::get_type() const
	{
		return IniEntityType::ValueCommentPair;
	}

	std::string IniValueCommentPair::to_string() const
	{
		return get_value() + get_comment();
	}

	std::string IniValueCommentPair::get_value() const
	{
		return get_value(false);
	}

	std::string IniValueCommentPair::get_value(const bool& trimWhitespace) const
	{
		return trimWhitespace ? trim(m_value) : m_value;
	}

	std::string IniValueCommentPair::get_comment() const
	{
		return m_commentPrefix != '\0' ? std::string(1, m_commentPrefix) + m_commentText : "";
	}

	void IniValueCommentPair::set_value(const std::string& value)
	{
		m_value = value;
	}

	void IniValueCommentPair::set_comment(const IniCommentPrefix& newPrefix, const std::string& newText)
	{
		m_commentPrefix = static_cast<char>(newPrefix);
		m_commentText = newText;
	}

	std::string IniValueCommentPair::extract_value(const std::string& iniValue)
	{
		const std::string INI_COMMENT = extract_ini_comment(iniValue);

		if (iniValue.length() > INI_COMMENT.length())
		{
			return iniValue.substr(0, (iniValue.length() - INI_COMMENT.length()));
		}

		return "";
	}

	char IniValueCommentPair::extract_comment_prefix(const std::string& iniValue)
	{
		const std::string INI_COMMENT = extract_ini_comment(iniValue);

		if (!INI_COMMENT.empty())
		{
			return INI_COMMENT[0];
		}

		return '\0';
	}

	std::string IniValueCommentPair::extract_comment_text(const std::string& iniValue)
	{
		const std::string INI_COMMENT = extract_ini_comment(iniValue);

		if (INI_COMMENT.length() > 1)
		{
			return INI_COMMENT.substr(1, INI_COMMENT.length() - 1);
		}

		return iniValue;
	}
}
