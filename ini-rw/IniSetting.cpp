// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniSetting.hpp"
#include <fstream>

namespace IniRW
{
	IniSetting::IniSetting(const std::string& iniFilePath)
	{
		this->iniFilePath = iniFilePath;

		LoadIniFile(iniFilePath);
	}

	bool IniSetting::IsLoaded() const
	{
		return loaded;
	}

	void IniSetting::LoadIniFile(const std::string& iniFilePath)
	{
		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			bool sectionEncountered = false;
			std::string currentSectionName;
			std::string currentLine;

			// Read every line from the INI file
			while (std::getline(fileStream, currentLine))
			{
				if (currentLine.empty() || currentLine == "\n")
				{

				}
				else if (sectionEncountered)
				{

				}
			}

			loaded = true;
		}
	}



}
