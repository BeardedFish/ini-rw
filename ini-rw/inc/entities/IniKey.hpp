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
		std::string comment;

	public:
		/// <summary>
		/// Constructor for creating the Key class. By calling this constructor, the section, name, and value of this key will be set to those specified in the parameter of
		/// the function.The comment of this key will be set to empty.
		/// </summary>
		/// <param name="section">The name of the section that this key belongs too.</param>
		/// <param name="name">The name of this key.</param>
		/// <param name="value">The value of this key.</param>
		/// <param name="comment">The comment attached to this key.</param>
		IniKey(const std::string& section, const std::string& name, const std::string& value, const std::string& comment);

		/// <summary>
		/// Gets the INI entity type of this class.
		/// </summary>
		/// <returns>The return value will always be IniEnityType::Key.</returns>
		IniEntityType GetType() override;

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
		std::string GetComment() const;

		/// <summary>
		/// Sets the value for this key to the one specified in the function parameter.
		/// </summary>
		/// <param name="newValue">The new value this key should have.</param>
		void SetValue(const std::string& newValue);
	};
}