// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../inc/entities/IniKey.hpp"
#include "../../inc/algorithms/Parse.hpp"

namespace IniRW
{
	IniKey::IniKey(IniSection* iniSection, const std::string& name, const IniValueCommentPair& valueCommentPair)
	{
		m_iniSection = iniSection;
		m_name = name;
		ValueCommentPair = valueCommentPair;
	}

	IniEntityType IniKey::GetType() const
	{
		return IniEntityType::Key;
	}

	std::string IniKey::ToString() const
	{
		return GetName() + INI_KEY_VALUE_DELIMITER + ValueCommentPair.ToString();
	}

	IniSection* IniKey::GetSection() const
	{
		return m_iniSection;
	}

	std::string IniKey::GetName() const
	{
		return m_name;
	}
}
