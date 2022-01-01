// File Name:     IniSection.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniEntity.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace IniRW
{
	class IniSection : public IniEntity
	{
	private:
		std::string m_leadingWhitespace;
		std::string m_name;
		IniValueCommentPair m_extraData;
	public:
		IniSection(const std::string& name);
		IniSection(const std::string& leadingWhitespace, const std::string& name, IniValueCommentPair extraData);

		IniEntityType GetType() const override;

		std::string ToString() const override;

		std::string GetName() const;

		void SetLeadingWhitespace(const std::string& whitespace);
	private:
		bool IsWhitespace(const std::string& str);
	};
}
