// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "../enums/IniCommentPrefix.hpp"
#include "IniEntity.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace IniRW
{
	class IniKey : public IniEntity
	{
	private:
		std::string section;
		std::string name;
		IniValueCommentPair valueCommentPair;

	public:
		/// <summary>
		/// Creates an INI key object with a custom name, value, and inline comment.
		/// </summary>
		/// <param name="section">The name of the section that the key belongs to.</param>
		/// <param name="name">The name of the key.</param>
		/// <param name="valueCommentPair">The value and inline comment the key will hold.</param>
		IniKey(const std::string& section, const std::string& name, const IniValueCommentPair& valueCommentPair);

		/// <summary>
		/// Gets an enum that represents the type of INI entity this object is.
		/// </summary>
		/// <returns>The return value will always be IniEntityType::Key.</returns>
		IniEntityType GetType() const override;

		/// <summary>
		/// Converts the current state of this object to a formatted string. Refer to "Returns" for the format.
		/// </summary>
		/// <returns>A string in the format: "[KEY_NAME]=[KEY_VALUE][INLINE_COMMENT]" (excluding quotes).</returns>
		std::string ToString() const override;

		/// <summary>
		/// Gets the name of the INI section this key is attached to.
		/// </summary>
		/// <returns>A string which contains the name of the section this INI key is attached to.</returns>
		std::string GetSection() const;

		/// <summary>
		/// Gets the name of this INI key. The name is the value that appears on the left side of the equals sign.
		/// </summary>
		/// <returns>A string which contains the name of this INI key.</returns>
		std::string GetName() const;

		/// <summary>
		/// Gets the object which contains the value and inline comment attached to this INI key. The value and inline comment appear on the right side of the equals sign.
		/// </summary>
		/// <returns>An IniValueCommentPair object.</returns>
		IniValueCommentPair GetValueCommentPair() const;
	};
}