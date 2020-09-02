// File Name:     IniSetting.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "entities/IniEntity.hpp"
#include "entities/IniComment.hpp"
#include "entities/IniKey.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	class IniSetting
	{
	private:
		bool loaded;
		std::string iniFilePath;
		std::vector<IniEntity*> iniContents;

	public:
		/// <summary>
		/// Constructor for creating the IniSetting class. By calling this constructor, the INI file passed in the parameters is loaded in the class.
		/// </summary>
		/// <param name="iniFilePath">The path to the INI file to be loaded in the IniSetting class.</param>
		IniSetting(const std::string& iniFilePath);

		/// <summary>
		/// Deconstructor for the IniSetting class.
		/// </summary>
		~IniSetting();

		/// <summary>
		/// Returns a boolean that states whether the INI file was loaded succesfully or not.
		/// </summary>
		/// <returns>True if the INI file was loaded succesfully, if not, false.</returns>
		bool IsLoaded() const;

		/// <summary>
		/// Saves the contents of the INI file to the same path that it was loaded from.
		/// </summary>
		/// <returns>True if the INI file was saved succesfully, if not, false.</returns>
		bool SaveChanges();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="sectionName"></param>
		/// <param name="keyName"></param>
		/// <param name="keyValue"></param>
		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		/// <summary>
		/// Searches for a key under a specific section in the loaded INI file.
		/// </summary>
		/// <param name="sectionName">The name of the section which contains the key.</param>
		/// <param name="keyName">The name of the key to be searched for in the section.</param>
		/// <returns>If the key is found in the INI file, then a pointer to that Key is returned. If the key was not found, then a null pointer is returned.</returns>
		IniKey* GetKey(const std::string& sectionName, const std::string& keyName);

		/// <summary>
		/// Gets the file contents of the loaded INI file as a string.
		/// </summary>
		/// <returns>A string which contains the contents of the loaded INI file.</returns>
		std::string ToString();

	private:
		/// <summary>
		/// Loads an INI file's contents into the current instance of the class.
		/// </summary>
		/// <param name="iniFilePath">The path to the INI file.</param>
		void LoadIniFile(const std::string& iniFilePath);
	};
}