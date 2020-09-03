// File Name:     IniString.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "IniEntity.hpp"
#include "../enums/IniCommentPrefix.hpp"
#include <string>

namespace IniRW
{
	class IniComment : public IniEntity
	{
	private:
		IniCommentPrefix prefix;
		std::string text;

	public:
		/// <summary>
		/// Constructor for creating an INI comment. This constructor sets the prefix to "\0" and the text to an empty value.
		/// </summary>
		IniComment();

		/// <summary>
		/// Constructor for creating an INI comment. This constructor allows you to specify the prefix and text of the INI comment.
		/// </summary>
		/// <param name="prefix">The prefix of the INI comment.</param>
		/// <param name="text">The text of the INI comment.</param>
		IniComment(IniCommentPrefix prefix, const std::string& text);

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::Comment.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Gets the prefix character of this INI comment.
		/// </summary>
		/// <returns>A character of this INI comment.</returns>
		char GetPrefix() const;

		/// <summary>
		/// Gets the text of this INI comment.
		/// </summary>
		/// <returns>The text of this INI comment.</returns>
		std::string GetText() const;
	};
}