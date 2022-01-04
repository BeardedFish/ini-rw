// File Name:     IniSection.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniEntity.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace inirw
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

		virtual ~IniSection() {}

		IniEntityType get_type() const override;

		std::string to_string() const override;

		std::string get_name() const;

		void set_leading_whitespace(const std::string& whitespace);
	private:
		bool is_whitespace(const std::string& str);
	};
}
