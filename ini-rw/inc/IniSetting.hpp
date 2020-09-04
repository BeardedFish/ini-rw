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
		/// Copy constructor which performs a deep copy of an INI setting instance.
		/// </summary>
		/// <param name="iniSettings">The INI settings instance to be copied.</param>
		IniSetting(const IniSetting& iniSettings);

	private:
		/// <summary>
		/// Constructor for creating an IniSetting class. This constructor is private. In addition, it allows a programmer to set the "loaded" and "iniFilePath" variable
		/// values.
		/// </summary>
		/// <param name="loaded">States whether an INI file has been loaded into the INI settings instance or not.</param>
		/// <param name="iniFilePath">States the path to the INI file that was loaded.</param>
		IniSetting(const bool loaded, const std::string& iniFilePath);

	public:
		/// <summary>
		/// Deconstructor for the IniSetting class. When this deconstructor is called, all IniEntity* objects stored in this class are deallocated from the heap.
		/// </summary>
		~IniSetting();

		/// <summary>
		/// Overloaded operator which prints the INI contents to an output stream. This function prints the INI contents via the ToString() method.
		/// </summary>
		/// <param name="outputStream">The stream to print the INI contents to.</param>
		/// <param name="iniSettings">The INI settings instance.</param>
		/// <returns>The output stream object that was used to print the INI contents to.</returns>
		friend std::ostream& operator<<(std::ostream& outputStream, const IniSetting& iniSettings);

		/// <summary>
		/// Overloaded operator which returns a boolean that states whether an INI file is loaded in this INI settings instance or not.
		/// </summary>
		/// <returns>True if an INI file is loaded, if not, false.</returns>
		operator bool() const;

		/// <summary>
		/// Overloaded operator which searches for a key under a specific section in the loaded INI file.
		/// </summary>
		/// <param name="keyPair">
		/// The std::pair object which contains information about the key to be looked up in this INI settings instance. The first value in the pair is the section name and
		/// the second value is the key name.
		/// </param>
		/// <returns>If the key exists in the INI file, then the IniKey* is returned. If the key was not found, then a null pointer is returned.</returns>
		IniKey* operator[](const std::pair<std::string, std::string>& keyPair);

		/// <summary>
		/// Returns a boolean that states whether the INI file was loaded succesfully or not.
		/// </summary>
		/// <returns>True if the INI file was loaded succesfully, if not, false.</returns>
		bool IsLoaded() const;

		/// <summary>
		/// Gets the file contents of the loaded INI file as a string.
		/// </summary>
		/// <returns>A string which contains the contents of the loaded INI file.</returns>
		std::string ToString() const;

		/// <summary>
		/// Saves the contents of the INI file to the same path that it was loaded from.
		/// </summary>
		/// <returns>True if the INI file was saved succesfully, if not, false.</returns>
		bool SaveChanges();

		/// <summary>
		/// Saves the contents of the INI file to a specified path.
		/// </summary>
		/// <param name="savePath">The path to save the INI file.</param>
		/// <returns>True if the INI file was saved succesfully, if not, false.</returns>
		bool SaveChanges(const std::string& savePath);

		/// <summary>
		/// Clears all the INI contents for this IniSetting instance.
		/// </summary>
		void Clear();

		/// <summary>
		/// Updates a key under a specific section in the loaded INI file. If the key exists under the specified section then its value is updated. If the key does not exist under that
		/// section then the key is inserted under that section.
		/// </summary>
		/// <param name="sectionName">The name of the section where the key will be modified or inserted.</param>
		/// <param name="keyName">The name of the key to be added or updated.</param>
		/// <param name="keyValue">The value of the key that will be updated or added.</param>
		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		/// <summary>
		/// Searches for a key under a specific section in the loaded INI file.
		/// </summary>
		/// <param name="sectionName">The name of the section which contains the key.</param>
		/// <param name="keyName">The name of the key to be searched for in the section.</param>
		/// <returns>If the key exists in the INI file, then the IniKey* is returned. If the key was not found, then a null pointer is returned.</returns>
		IniKey* GetKey(const std::string& sectionName, const std::string& keyName);

	private:
		/// <summary>
		/// Loads an INI file's contents into the current instance of the class.
		/// </summary>
		/// <param name="iniFilePath">The path to the INI file.</param>
		void LoadIniFile(const std::string& iniFilePath);
	};
}