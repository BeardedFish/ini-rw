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
		/// <summary>
		/// Creates an INI value comment pair object with empty values.
		/// </summary>
		IniValueCommentPair();

		/// <summary>
		/// Creates an INI value comment pair object with values parsed from a string.
		/// </summary>
		/// <param name="data">The string to be parsed for data.</param>
		/// <example>
		/// If the string for the first parameter was "ABC ; 123" (excluding quotes), then the extracted value before the inline INI comment would be "ABC " and the inline
		/// INI comment would be "; 123".
		/// </example>
		IniValueCommentPair(const std::string& data);

	private:
		/// <summary>
		/// Creates an INI value comment pair object with a value and an inline INI comment.
		/// </summary>
		/// <param name="valueBeforeComment">The value before the inline INI comment.</param>
		/// <param name="commentPrefix">The INI comment prefix.</param>
		/// <param name="commentText">The INI comment text.</param>
		IniValueCommentPair(const std::string& valueBeforeComment, const char& commentPrefix, const std::string& commentText);

	public:
		/// <summary>
		/// Gets an enum that represents the type of INI entity this object is.
		/// </summary>
		/// <returns>The return value will always be IniEntityType::ValueCommentPair.</returns>
		IniEntityType GetType() const override;

		/// <summary>
		/// Converts the current state of this object to a formatted string. Refer to "Returns" for the format.
		/// </summary>
		/// <returns>A string in the format: "[VALUE][INI_COMMENT]" (excluding quotes). The returned string has the possibility of being empty.</returns>
		std::string ToString() const override;

		/// <summary>
		/// Gets the value before the inline INI comment. This value includes leading and trailing whitespace.
		/// </summary>
		/// <returns>A string which can contain leading and trailing whitespace. The returned string has the possibility of being empty.</returns>
		std::string GetValueBeforeComment() const;

		/// <summary>
		/// Gets the value before the inline INI comment attached to this instance.
		/// </summary>
		/// <param name="trimWhitespace">States whether leading and trailing whitespace should be trimmed on the return value or not.</param>
		/// <returns>
		/// A string which can contain leading and trailing whitespace if the first parameter is set to false. If the first parameter is set to true, then the string
		/// returned will not have leading and trailing whitespace. The returned string has the possibility of being empty.
		/// </returns>
		std::string GetValueBeforeComment(const bool& trimWhitespace) const;

		/// <summary>
		/// Gets the inline INI comment attached to this instance.
		/// </summary>
		/// <returns>
		/// If an inline INI comment is attached to this object, then a string in the format "[INI_COMMENT_PREFIX][INI_COMMENT_TEXT]" (excluding quotes) is returned. If no
		/// INI comment is attached, then an empty string is returned.
		/// </returns>
		std::string GetComment() const;

		/// <summary>
		/// Sets the value before the inline INI comment for this instance.
		/// </summary>
		/// <param name="newValue">The new value to be set.</param>
		void SetValueBeforeComment(const std::string& newValue);

		/// <summary>
		/// Sets the inline INI comment for this instance.
		/// </summary>
		/// <param name="prefix">The new comment prefix to be set for the INI comment.</param>
		/// <param name="text">The new text to be set for the INI comment.</param>
		void SetComment(const IniCommentPrefix& prefix, const std::string& text);

	private:
		/// <summary>
		/// Extracts an INI comment prefix from a string if it exists. Escaped INI comment prefixes are ignored.
		/// </summary>
		/// <param name="iniValue">The string to be parsed.</param>
		/// <returns>
		/// If an INI comment exists in the string, then the prefix char of the comment is returned. This char can be either ';' or '#'. If an INI comment does not exist in
		/// the string, then the char '\0' is returned.
		/// </returns>
		char ExtractCommentPrefix(const std::string& iniValue);

		/// <summary>
		/// Extracts the text from an INI comment in a string if it exists.
		/// </summary>
		/// <param name="iniValue">The string to be parsed.</param>
		/// <returns>
		/// If an INI comment exists in the string, then the. This does not include the INI comment prefix. If an INI comment does not exist in the string, then an empty
		/// string is returned.
		/// </returns>
		std::string ExtractCommentText(const std::string& iniValue);

		/// <summary>
		/// Extracts the value before an INI comment.
		/// </summary>
		/// <param name="iniValue">The string to be parsed.</param>
		/// <returns>
		/// If an INI comment exists in the string, then a substring from index 0 to the prefix character of the INI comment is returned. If no INI comment exists, then the
		/// original value of the string is returned.
		/// </returns>
		std::string ExtractValueBeforeComment(const std::string& iniValue);
	};
}