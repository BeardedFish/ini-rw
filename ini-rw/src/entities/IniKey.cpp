// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../inc/entities/IniKey.hpp"
#include "../../inc/algorithms/Parse.hpp"

namespace IniRW
{
	IniKey::IniKey(const std::string& section, const std::string& name, const IniValueCommentPair& valueCommentPair)
	{
		m_section = section;
		m_name = name;
		m_valueCommentPair = valueCommentPair;
	}

	IniEntityType IniKey::GetType() const
	{
		return IniEntityType::Key;
	}

	std::string IniKey::ToString() const
	{
		return GetName() + INI_KEY_VALUE_DELIMITER + m_valueCommentPair.ToString();
	}

	std::string IniKey::GetSection() const
	{
		return m_section;
	}

	std::string IniKey::GetName() const
	{
		return m_name;
	}

	IniValueCommentPair IniKey::GetValueCommentPair() const
	{
		return m_valueCommentPair;
	}
}