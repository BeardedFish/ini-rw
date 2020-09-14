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
		std::string leadingWhitespace;
		std::string name;
		IniValueCommentPair extraData;

	public:
		/// <summary>
		/// Creates an INI section object with a custom name.
		/// </summary>
		/// <param name="name">The name of the INI section.</param>
		IniSection(const std::string& name);

		/// <summary>
		/// Creates an INI section object with leading whitespace, a custom name, and extra data.
		/// </summary>
		/// <param name="whitespace">The string which contains whitespace.</param>
		/// <param name="name">The name of the INI section.</param>
		/// <param name="extraData">The extra data attached to the INI section. This can either be garbage data or an inline INI comment.</param>
		/// <exception cref="std::exception">This exception will be thrown if the first parameter contains a non-whitespace character.</exception>
		IniSection(const std::string& leadingWhitespace, const std::string& name, IniValueCommentPair extraData);

		/// <summary>
		/// Gets an enum that represents the type of INI entity this object is.
		/// </summary>
		/// <returns>The return value will always be IniEntityType::Section.</returns>
		IniEntityType GetType() const override;

		/// <summary>
		/// Converts the current state of this object to a formatted string. Refer to "Returns" for the format.
		/// </summary>
		/// <returns>
		/// A string in the format: "[LEADING_WHITESPACE][SECTION_NAME][EXTRA_DATA]" (excluding quotes). The SECTION_NAME includes a leading "[" character  and a trailing
		/// "]" character.
		/// </returns>
		std::string ToString() const override;

		/// <summary>
		/// Gets the name of this INI section.
		/// </summary>
		/// <returns>A string which contains the name of this INI key.</returns>
		std::string GetName() const;

		/// <summary>
		/// Sets the leading whitespace for this INI section instance. Leading whitespace appears before the INI section name.
		/// </summary>
		/// <param name="whitespace">The string which contains whitespace.</param>
		/// <exception cref="std::exception">This exception will be thrown if the first parameter contains a non-whitespace character.</exception>
		void SetLeadingWhitespace(const std::string& whitespace);

	private:
		/// <summary>
		/// States whether a string contains only whitespace or not.
		/// </summary>
		/// <param name="str">The string to be evaluated.</param>
		/// <returns>True if the string contains only whitespace, if not, false.</returns>
		bool IsWhitespace(const std::string& str);
	};
}