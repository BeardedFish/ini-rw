// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../inc/entities/IniKey.hpp"
#include "../../inc/algorithms/Parse.hpp"

namespace IniRW
{
	IniKey::IniKey(const std::string& section, const std::string& name, const IniValueCommentPair& valueCommentPair)
	{
		this->section = section;
		this->name = name;
		this->valueCommentPair = valueCommentPair;
	}

	IniEntityType IniKey::GetType() const
	{
		return IniEntityType::Key;
	}

	std::string IniKey::ToString() const
	{
		return GetName() + INI_KEY_VALUE_DELIMITER + valueCommentPair.ToString();
	}

	std::string IniKey::GetSection() const
	{
		return section;
	}

	std::string IniKey::GetName() const
	{
		return name;
	}

	IniValueCommentPair IniKey::GetValueCommentPair() const
	{
		return valueCommentPair;
	}
}