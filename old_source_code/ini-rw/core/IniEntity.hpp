// File Name:     IniEntity.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

#include "../enums/IniEntityType.hpp"

namespace IniRW
{
	class IniEntity
	{
	private:
		IniEntityType type;
		void* data;

	public:
		/**
		 * Function Name:     IniEntity()
		 *
		 * Brief:			  Constructor for creating the IniEntity class. By calling this constructor, the type of entity will be BlankLine and the data stored in the
		 *                    entity will be a null pointer.
		 * 
		 * Parameters:        None.
		 *
		 * Return:            Nothing.
		 */
		IniEntity();

		/**
		 * Function Name:     IniEntity()
		 *
		 * Brief:             Constructor for creating the IniEntity class. This constructor sets the type and data, however, the data set with the type should follow
		 *                    the convention of this libraries design (refer to "Parameters" for more information).
		 *
		 * Parameters:        type - The type this entity should be.
		 *                    data - The data this entity should store. By this libraries design, if the type is BlankLine then the data should be a null pointer. If
		 *                           the type is either Comment, Section, or UnknownValue then the data should be a string pointer. If the type is Key then the data
		 *                           should be a Key pointer.
		 *
		 * Return:            Nothing.
		 */
		IniEntity(IniEntityType type, void* data);

		/**
		 * Function Name:     GetData()
		 *
		 * Brief:             Gets the data of this INI entity. The data of the INI entity depends on what kind of type it is.
		 *
		 * Parameters:        None.
		 *
		 * Return:            By this libraries design, if the entity type is BlankLine then the data returned is null pointer. If the type is either Comment, Section, 
		 *                    or UnknownValue then a string pointer is returned. If the type is Key then a Key pointer is returned.
		 *
		 *                    NOTE: You must cast the void pointer returned to the data type in order to access its contents.
		 * 
		 *                          Example: std::string* data = static_cast<std::string*>(data);
		 */
		void* GetData();

		/**
		 * Function Name:     GetType()
		 *
		 * Brief:             Gets the data of this INI entity. The data of the INI entity depends on what kind of type it is.
		 *
		 * Parameters:        None.
		 *
		 * Return:            An enum class IniEntityType which contains the type this INI entity is.
		 */
		IniEntityType GetType();
	};
} // End IniRW namespace