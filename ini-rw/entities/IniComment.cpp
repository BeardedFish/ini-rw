// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniComment.hpp"

namespace IniRW
{
	IniComment::IniComment() : IniComment('\0', "")
	{

	}

	IniComment::IniComment(const char prefix, const std::string& text) : IniEntity()
	{
		this->prefix = prefix;
		this->text = text;
	}

	IniEntityType IniComment::GetType()
	{
		return IniEntityType::Comment;
	}

	std::string IniComment::GetText() const
	{
		return text;
	}
}