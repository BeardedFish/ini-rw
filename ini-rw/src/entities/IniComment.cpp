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

	std::string IniComment::ToString() const
	{
		std::string result;

		result += GetPrefix();
		result += GetText();

		return result;
	}

	char IniComment::GetPrefix() const
	{
		return static_cast<char>(prefix);
	}

	std::string IniComment::GetText() const
	{
		return text;
	}

	void IniComment::SetPrefix(const IniCommentPrefix& newPrefix)
	{
		prefix = newPrefix;
	}
}