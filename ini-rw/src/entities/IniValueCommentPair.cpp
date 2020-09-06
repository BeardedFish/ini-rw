// File Name:     IniValueCommentPair.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#include "../../inc/entities/IniValueCommentPair.hpp"
#include "../../inc/algorithms/Parse.hpp"
#include <iostream>

namespace IniRW
{
	// TODO: REFACTOR CONSTRUCTORS (USING PRIVATE CONSTRUCTOR)...

	IniValueCommentPair::IniValueCommentPair()
	{
		this->valueBeforeComment = "";
		this->commentPrefix = '\0';
		this->commentText = "";
	}

	IniValueCommentPair::IniValueCommentPair(const std::string& text)
	{
		const std::vector<char> INI_COMMENT_PREFIXES = { static_cast<char>(IniCommentPrefix::Pound), static_cast<char>(IniCommentPrefix::Semicolon) };

		this->valueBeforeComment = GetStringBeforeComment(INI_COMMENT_PREFIXES, text);
		this->commentPrefix = GetCommentPrefix(INI_COMMENT_PREFIXES, text);
		this->commentText = GetCommentText(INI_COMMENT_PREFIXES, text);
	}

	IniEntityType IniValueCommentPair::GetType()
	{
		return IniEntityType::ValueCommentPair;
	}

	std::string IniValueCommentPair::ToString() const
	{
		return GetValueBeforeComment() + GetComment();
	}

	std::string IniValueCommentPair::GetValueBeforeComment() const
	{
		return valueBeforeComment;
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
}