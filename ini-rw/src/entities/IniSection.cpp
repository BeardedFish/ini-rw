// File Name:     IniSection.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/entities/IniSection.hpp"
#include "../../inc/algorithms/Parse.hpp"

namespace IniRW
{
	IniSection::IniSection(const std::string& name) : IniSection("", name, IniValueCommentPair())
	{

	}

	IniSection::IniSection(const std::string& leadingWhitespace, const std::string& name, IniValueCommentPair extraData)
		: m_name(name), m_extraData(extraData)
	{
		set_leading_whitespace(leadingWhitespace);
	}

	IniEntityType IniSection::get_type() const
	{
		return IniEntityType::Section;
	}

	std::string IniSection::to_string() const
	{
		return m_leadingWhitespace + INI_SECTION_BEGINNING + get_name() + INI_SECTION_ENDING + m_extraData.to_string();
	}

	std::string IniSection::get_name() const
	{
		return m_name;
	}

	void IniSection::set_leading_whitespace(const std::string& whitespace)
	{
		if (!is_whitespace(whitespace))
		{
			throw std::exception("The string contains an illegal character!");
		}

		m_leadingWhitespace = whitespace;
	}

	bool IniSection::is_whitespace(const std::string& str)
	{
		for (const char& ch : str)
		{
			if (!iswspace(ch))
			{
				return false;
			}
		}

		return true;
	}
}
