// File Name:     IniKey.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#include "../../include/entities/IniKey.hpp"
#include "../../include/algorithms/Parse.hpp"

namespace inirw
{
	IniKey::IniKey(IniSection* iniSection, const std::string& name, const IniValueCommentPair& valueCommentPair)
		: m_iniSection(iniSection), m_name(name), ValueCommentPair(valueCommentPair)
	{

	}

	IniEntityType IniKey::get_type() const
	{
		return IniEntityType::Key;
	}

	std::string IniKey::to_string() const
	{
		return get_name() + INI_KEY_VALUE_DELIMITER + ValueCommentPair.to_string();
	}

	IniSection* IniKey::get_section() const
	{
		return m_iniSection;
	}

	std::string IniKey::get_name() const
	{
		return m_name;
	}
}
