// File Name:     IniSetting.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "entities/IniEntity.hpp"
#include "entities/IniString.hpp"
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