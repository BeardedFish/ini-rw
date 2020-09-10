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
		std::string valueBeforeComment;
		char commentPrefix;
		std::string commentText;

	public:
		IniValueCommentPair();

		IniValueCommentPair(const std::string& value);

	private:
		IniValueCommentPair(const std::string& valueBeforeComment, const char& commentPrefix, const std::string& commentText);

	public:
		IniEntityType GetType() override;

		std::string ToString() const override;

		std::string GetValueBeforeComment() const;

		std::string GetValueBeforeComment(const bool& trimWhitespace) const;

		std::string GetComment() const;

		void SetValueBeforeComment(const std::string& newValue);

		void SetComment(const IniCommentPrefix& prefix, const std::string& text);

	private:
		char ExtractCommentPrefix(const std::string& iniValue);

		std::string ExtractCommentText(const std::string& iniValue);

		std::string ExtractValueBeforeComment(const std::string& iniValue);
	};
}