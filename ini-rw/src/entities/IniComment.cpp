// File Name:     IniComment.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../../inc/entities/IniComment.hpp"

namespace IniRW
{
	IniComment::IniComment() : IniComment(IniCommentPrefix::Semicolon, "")
	{

	}

	IniComment::IniComment(IniCommentPrefix prefix, const std::string& text) : IniEntity()
	{
		this->prefix = prefix;
		this->text = text;
	}

	IniEntityType IniComment::GetType()
	{
		return IniEntityType::Comment;
	}

	char IniComment::GetPrefix() const
	{
		return prefix == IniCommentPrefix::Pound ? '#' : ';';
	}

	std::string IniComment::GetText() const
	{
		return text;
	}
}