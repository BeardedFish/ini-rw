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
	{
		SetLeadingWhitespace(leadingWhitespace);
		m_name = name;
		m_extraData = extraData;
	}

	IniEntityType IniSection::GetType() const
	{
		return IniEntityType::Section;
	}

	std::string IniSection::ToString() const
	{
		return m_leadingWhitespace + INI_SECTION_BEGINNING + GetName() + INI_SECTION_ENDING + m_extraData.ToString();
	}

	std::string IniSection::GetName() const
	{
		return m_name;
	}

	void IniSection::SetLeadingWhitespace(const std::string& whitespace)
	{
		if (!IsWhitespace(whitespace))
		{
			throw std::exception("The string contains an illegal character!");
		}

		m_leadingWhitespace = whitespace;
	}

	bool IniSection::IsWhitespace(const std::string& str)
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
