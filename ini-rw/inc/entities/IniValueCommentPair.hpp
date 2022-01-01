// File Name:     IniValueCommentPair.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Friday, September 4, 2020

#pragma once

#include "IniEntity.hpp"
#include "../enums/IniCommentPrefix.hpp"

namespace IniRW
{
	class IniValueCommentPair : public IniEntity
	{
	private:
		std::string m_valueBeforeComment;
		char m_commentPrefix;
		std::string m_commentText;
	public:
		IniValueCommentPair();
		IniValueCommentPair(const std::string& data);
	private:
		IniValueCommentPair(const std::string& valueBeforeComment, const char& commentPrefix, const std::string& commentText);
	public:
		IniEntityType get_type() const override;

		std::string to_string() const override;

		std::string get_value_before_comment() const;

		std::string get_value_before_comment(const bool& trimWhitespace) const;

		std::string get_comment() const;

		void set_value_before_comment(const std::string& newValue);

		void set_comment(const IniCommentPrefix& prefix, const std::string& text);
	private:
		char extract_comment_prefix(const std::string& iniValue);

		std::string extract_comment_text(const std::string& iniValue);

		std::string extract_value_before_comment(const std::string& iniValue);
	};
}
