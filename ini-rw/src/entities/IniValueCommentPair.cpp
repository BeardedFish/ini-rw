// File Name:     IniValueCommentPair.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#include "../../inc/entities/IniValueCommentPair.hpp"
#include "../../inc/algorithms/Parse.hpp"
#include <iostream>

namespace IniRW
{
	IniValueCommentPair::IniValueCommentPair() : IniValueCommentPair("", '\0', "")
	{

	}

	IniValueCommentPair::IniValueCommentPair(const std::string& data) : IniValueCommentPair(ExtractValueBeforeComment(data), ExtractCommentPrefix(data), ExtractCommentText(data))
	{

	}

	IniValueCommentPair::IniValueCommentPair(const std::string& valueBeforeComment, const char& commentPrefix, const std::string& commentText)
	{
		this->valueBeforeComment = valueBeforeComment;
		this->commentPrefix = commentPrefix;
		this->commentText = commentText;
	}

	IniEntityType IniValueCommentPair::GetType() const
	{
		return IniEntityType::ValueCommentPair;
	}

	std::string IniValueCommentPair::ToString() const
	{
		return GetValueBeforeComment() + GetComment();
	}

	std::string IniValueCommentPair::GetValueBeforeComment() const
	{
		return GetValueBeforeComment(false);
	}

	std::string IniValueCommentPair::GetValueBeforeComment(const bool& trimWhitespace) const
	{
		return trimWhitespace ? Trim(valueBeforeComment) : valueBeforeComment;
	}

	std::string IniValueCommentPair::GetComment() const
	{
		return commentPrefix != '\0' ? std::string(1, commentPrefix) + commentText : "" ;
	}

	void IniValueCommentPair::SetValueBeforeComment(const std::string& newValue)
	{
		valueBeforeComment = newValue;
	}

	void IniValueCommentPair::SetComment(const IniCommentPrefix& newPrefix, const std::string& newText)
	{
		commentPrefix = static_cast<char>(newPrefix);
		commentText = newText;
	}

	std::string IniValueCommentPair::ExtractValueBeforeComment(const std::string& iniValue)
	{
		const std::string INI_COMMENT = ExtractIniComment(iniValue);

		if (iniValue.length() > INI_COMMENT.length())
		{
			return iniValue.substr(0, (iniValue.length() - INI_COMMENT.length()));
		}

		return "";
	}

	char IniValueCommentPair::ExtractCommentPrefix(const std::string& iniValue)
	{
		const std::string INI_COMMENT = ExtractIniComment(iniValue);

		if (!INI_COMMENT.empty())
		{
			return INI_COMMENT[0];
		}

		return '\0';
	}

	std::string IniValueCommentPair::ExtractCommentText(const std::string& iniValue)
	{
		const std::string INI_COMMENT = ExtractIniComment(iniValue);

		if (INI_COMMENT.length() > 1)
		{
			return INI_COMMENT.substr(1, INI_COMMENT.length() - 1);
		}

		return iniValue;
	}
}