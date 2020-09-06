// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../inc/entities/IniKey.hpp"

namespace IniRW
{
	IniKey::IniKey(const std::string& section, const std::string& name, const std::string& value)
	{
		this->section = section;
		this->name = name;
		this->keyCommentPair = IniValueCommentPair(value);
	}

	IniKey::IniKey(const std::string& section, const std::string& name, const std::string& value, const IniCommentPrefix& commentPrefix, const std::string& commentText) : IniKey(section, name, value)
	{
		//this->comment = new IniComment(commentPrefix, commentText);
	}

	IniEntityType IniKey::GetType()
	{
		return IniEntityType::Key;
	}

	std::string IniKey::ToString() const
	{
		std::string result;

		result += GetName() + "=" + keyCommentPair.ToString();

		return result;
	}

	bool IniKey::HasComment() const
	{
		return true; // comment != nullptr;
	}

	std::string IniKey::GetSection() const
	{
		return section;
	}

	std::string IniKey::GetName() const
	{
		return name;
	}

	std::string IniKey::GetValue() const
	{
		return keyCommentPair.GetValueBeforeComment();
	}

	/*IniComment* IniKey::GetComment() const
	{
		return comment;
	}*/

	void IniKey::SetValue(const std::string& newValue)
	{
		//value = newValue;
	}
}