// File Name:     IniValueCommentPair.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#pragma once

#include "IniEntity.hpp"
#include "../enums/IniCommentPrefix.hpp"

namespace inirw
{
	class IniValueCommentPair : public IniEntity
	{
	private:
		std::string m_value;
		char m_commentPrefix;
		std::string m_commentText;
	public:
		IniValueCommentPair();
		IniValueCommentPair(const std::string& data);
	private:
		IniValueCommentPair(const std::string& value, const char& commentPrefix, const std::string& commentText);
	public:
		IniEntityType get_type() const override;

		std::string to_string() const override;

		std::string get_value() const;

		std::string get_value(const bool& trimWhitespace) const;

		std::string get_comment() const;

		void set_value(const std::string& value);

		void set_comment(const IniCommentPrefix& prefix, const std::string& text);
	private:
		char extract_comment_prefix(const std::string& iniValue);

		std::string extract_comment_text(const std::string& iniValue);

		std::string extract_value(const std::string& iniValue);
	};
}
