// File Name:     Key.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	class Key
	{
	private:
		std::string section;
		std::string name;
		std::string value;
		std::string comment;

	public:
		/**
		 * Function Name:     Key()
		 *
		 * Brief:             Constructor for creating the Key class. By calling this constructor, the section, name, and value of this key will be set to those
		 *                    specified in the parameter of the function. The comment of this key will be set to empty.
		 *
		 * Parameters:        section - The name of the section that this key belongs too.
		 *                    name - The name of this key.
		 *                    value - The value of this key.
		 *
		 * Return:            Nothing.
		 */
		Key(const std::string& section, const std::string& name, const std::string& value);

		/**
		 * Function Name:     Key()
		 *
		 * Brief:             Constructor for creating the Key class. By calling this constructor, the section, name, value, and comment of this key will be set to
		 *                    those specified in the parameter of the function. The comment of this key will be set to empty.
		 *
		 * Parameters:        section - The name of the section that this key belongs too.
		 *                    name - The name of this key.
		 *                    value - The value of this key.
		 *                    comment - The comment attached to this key.
		 *
		 * Return:            Nothing.
		 */
		Key(const std::string& section, const std::string& name, const std::string& value, const std::string& comment);

		/**
		 * Function Name:     GetSection()
		 *
		 * Brief:             Gets the section name that this key belongs too.
		 *
		 * Parameters:        None.
		 *
		 * Return:            A string which contains the section name that this key belongs too.
		 */
		std::string GetSection();

		/**
		 * Function Name:     GetName()
		 *
		 * Brief:             Gets the name of this key.
		 *
		 * Parameters:        None.
		 *
		 * Return:            A string which contains the name of this key.
		 */
		std::string GetName();

		/**
		 * Function Name:     GetValue()
		 *
		 * Brief:             Gets the value of this key.
		 *
		 * Parameters:        None.
		 *
		 * Return:            A string which contains the value of this key.
		 */
		std::string GetValue();

		/**
		 * Function Name:     GetComment()
		 *
		 * Brief:             Gets the comment attached to this key.
		 *
		 * Parameters:        None.
		 *
		 * Return:            A string which contains the comment attached to this key.
		 */
		std::string GetComment();
		
		/**
		 * Function Name:     SetValue()
		 *
		 * Brief:             Sets the value for this key to the one specified in the function parameter.
		 *
		 * Parameters:        newValue - The new value this key should have.
		 *
		 * Return:            Nothing.
		 */
		void SetValue(const std::string& newValue);
	};
} // End IniRW namespace