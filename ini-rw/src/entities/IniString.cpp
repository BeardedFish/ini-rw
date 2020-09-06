// File Name:     IniString.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#include "../../inc/entities/IniString.hpp"
#include "../../inc/algorithms/Parse.hpp"
#include <iostream>

namespace IniRW
{
	// TODO: REFACTOR CONSTRUCTORS (USING PRIVATE CONSTRUCTOR)...

	IniString::IniString()
	{
		this->valueBeforeComment = "";
		this->commentPrefix = '\0';
		this->commentText = "";
	}

	IniString::IniString(const std::string& text)
	{
		const std::vector<char> INI_COMMENT_PREFIXES = { static_cast<char>(IniCommentPrefix::Pound), static_cast<char>(IniCommentPrefix::Semicolon) };

		this->valueBeforeComment = GetStringBeforeComment(INI_COMMENT_PREFIXES, text);
		this->commentPrefix = GetCommentPrefix(INI_COMMENT_PREFIXES, text);
		this->commentText = GetCommentText(INI_COMMENT_PREFIXES, text);
	}

	IniEntityType IniString::GetType()
	{
		return IniEntityType::String;
	}

	std::string IniString::ToString() const
	{
		return GetValueBeforeComment() + GetComment();
	}

	std::string IniString::GetValueBeforeComment() const
	{
		return valueBeforeComment;
	}

	std::string IniString::GetComment() const
	{
		return commentPrefix != '\0' ? std::string(1, commentPrefix) + commentText : "" ;
	}

	void IniString::SetValueBeforeComment(const std::string& newValue)
	{
		valueBeforeComment = newValue;
	}

	void IniString::SetComment(const IniCommentPrefix& newPrefix, const std::string& newText)
	{
		commentPrefix = static_cast<char>(newPrefix);
		commentText = newText;
	}
}