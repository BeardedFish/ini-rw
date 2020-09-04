// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "IniEntity.hpp"
#include "IniComment.hpp"
#include <string>

namespace IniRW
{
	class IniKey : public IniEntity
	{
	private:
		std::string section;
		std::string name;
		std::string value;
		IniComment* comment;

	public:
		/// <summary>
		/// Creates an INI key with a specified section name, key name, and key value.
		/// </summary>
		/// <param name="section">The name of the section that this key belongs too.</param>
		/// <param name="name">The name of this key.</param>
		/// <param name="value">The value of this key.</param>
		IniKey(const std::string& section, const std::string& name, const std::string& value);

		/// <summary>
		/// Creates an INI key with a specified section name, key name, key value, and a comment.
		/// </summary>
		/// <param name="section">The name of the section that this key belongs too.</param>
		/// <param name="name">The name of this key.</param>
		/// <param name="value">The value of this key.</param>
		/// <param name="commentPrefix">The prefix of the comment attached to this key.</param>
		/// <param name="commentText">The text of the comment attached to this key.</param>
		IniKey(const std::string& section, const std::string& name, const std::string& value, const IniCommentPrefix& commentPrefix, const std::string& commentText);

		/// <summary>
		/// If an INI comment is attached to this key, then it is deallocated from the heap via this deconstructor. If no comment is attached then this deconstructor does
		/// nothing.
		/// </summary>
		~IniKey();

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::Key.</returns>
		IniEntityType GetType() override;

		/// <summary>
		/// Returns the string representation of this INI key.
		/// </summary>
		/// <returns>A string in the format: "KEY_NAME=KEY_VALUE INI_COMMENT" (excluding quotes).</returns>
		std::string ToString() const override;

		/// <summary>
		/// States whether this INI key has a comment attached to it or not.
		/// </summary>
		/// <returns>True if this key has a comment attached to it, if not, false.</returns>
		bool HasComment() const;

		/// <summary>
		/// Gets the section name that this key belongs too.
		/// </summary>
		/// <returns>A string which contains the section name that this key belongs too.</returns>
		std::string GetSection() const;

		/// <summary>
		/// Gets the name of this key.
		/// </summary>
		/// <returns>A string which contains the name of this key.</returns>
		std::string GetName() const;

		/// <summary>
		/// Gets the value of this INI key.
		/// </summary>
		/// <returns>A string which contains the value of this key.</returns>
		std::string GetValue() const;

		/// <summary>
		/// Gets the comment attached to this key.
		/// </summary>
		/// <returns>A string which contains the comment attached to this key. If the string returned is empty, then that means that this key doesn't have a comment.</returns>
		IniComment* GetComment() const;

		/// <summary>
		/// Sets the value for this key to the one specified in the function parameter.
		/// </summary>
		/// <param name="newValue">The new value this key should have.</param>
		void SetValue(const std::string& newValue);
	};
}