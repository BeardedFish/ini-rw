// File Name:     IniString.hpp
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
		/// <summary>
		/// Creates an empty INI string.
		/// </summary>
		IniValueCommentPair();

		/// <summary>
		/// Holds a string in an INI file.
		/// </summary>
		/// <param name="value">The value that this INI string will hold.</param>
		IniValueCommentPair(const std::string& value);

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::String.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Returns the string value that is held in this INI string instance.
		/// </summary>
		/// <returns>A string in the format: "[VALUE_BEFORE_COMMENT][INI_COMMENT]" (excluding quotes).</returns>
		std::string ToString() const override;

		/// <summary>
		/// Gets the value before the INI comment prefix character.
		/// </summary>
		/// <returns>A string that holds the current value of this INI string instance..</returns>
		std::string GetValueBeforeComment() const;

		/// <summary>
		/// Gets the comment of this INI string instance.
		/// </summary>
		/// <returns>
		/// If no comment exists, then an empty string is returned. If a comment exists, then a string in this format is returned: "[COMMENT_PREFIX][COMMENT_TEXT]" (excluding
		/// quotes).
		/// </returns>
		std::string GetComment() const;

		/// <summary>
		/// Sets the value before the the INI comment for this INI string instance.
		/// </summary>
		/// <param name="newValue">The new value to be set.</param>
		void SetValueBeforeComment(const std::string& newValue);

		/// <summary>
		/// Sets the comment for this INI string instance.
		/// </summary>
		/// <param name="prefix">The prefix of the INI comment.</param>
		/// <param name="text">The text of the INI comment.</param>
		void SetComment(const IniCommentPrefix& prefix, const std::string& text);
	};
}