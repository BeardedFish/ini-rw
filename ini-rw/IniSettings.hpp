// File Name:     IniSettings.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

#include "core/IniEntity.hpp"
#include "core/Key.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	class IniSettings
	{
	private:
		bool loaded;
		std::string iniFilePath;
		std::vector<IniEntity> iniContents;

	public:
		/**
		 * Function Name:     IniSettings()
		 *
		 * Brief:             Constructor for creating the IniSetting class. By calling this constructor, the INI file passed in the parameters is loaded in
		 *                    the class.
		 *
		 * Parameters:        iniFilePath - The path to the INI file to be loaded in the IniSetting class.
		 *
		 * Return:            Nothing. To make sure that the INI file was loaded succesfully check the IsLoaded() function.
		 */
		IniSettings(const std::string& iniFilePath);

		/**
		 * Function Name:     ~IniSettings()
		 *
		 * Brief:             Deconstructor for the IniSettings class. By calling this deconstructor, all memory allocated to the heap from the instance
		 *                    of this class will be deallocated.
		 *
		 * Parameters:        None.
		 *
		 * Return:            Nothing.
		 */
		~IniSettings();

		/**
		 * Function Name:     IsLoaded()
		 *
		 * Brief:             Returns a boolean that states whether the INI file was loaded succesfully or not.
		 *
		 * Parameters:        None.
		 *
		 * Return:            True if the INI file was loaded succesfully, if not, false.
		 */
		bool IsLoaded();

		/**
		 * Function Name:     Save()
		 *
		 * Brief:             Saves the file contents of the INI file to the same path that it was loaded from.
		 *
		 * Parameters:        None.
		 *
		 * Return:            True if the INI file was saved succesfully, if not, false.
		 */
		bool Save();
		
		/**
		 * Function Name:     GetKey()
		 *
		 * Brief:             Searches for a key under a specific section in the loaded INI file.
		 *
		 * Parameters:        sectionName - The name of the section which contains the key.
		 *                    keyName - The name of the key to be searched for in the section.
		 *
		 * Return:            If the key is found in the INI file, then a pointer to that Key is returned. If the key was not found, then a null pointer is
		 *                    returned.
		 */
		Key* GetKey(const std::string& sectionName, const std::string& keyName);

		/**
		 * Function Name:     WriteKeyValue()
		 *
		 * Brief:             Adds the key under a section if it does not exist. If the key already exists, then its value is overwritten.
		 *
		 * Parameters:        sectionName - The name of the section which contains the key.
		 *                    keyName - The name of the key which contains the value to be added/overwritten.
		 *                    keyValue - The new value of the key.
		 *
		 * Return:            Nothing.
		 */
		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		/**
		 * Function Name:     ToString()
		 *
		 * Brief:             Converts the loaded INI file contents into its original string format.
		 *
		 * Parameters:        None.
		 *
		 * Return:            A string which contains the loaded INI file contents.
		 */
		std::string ToString();

	private:
		/**
		 * Function Name:     loadIniFile()
		 *
		 * Brief:             Loads an INI files contents into the current instance of the class.
		 *
		 * Parameters:        None.
		 *
		 * Return:            Nothing.
		 */
		void loadIniFile();

	};
} // End IniRW namespace