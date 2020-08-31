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
		IniSetting(const std::string& iniFilePath);

		bool IsLoaded() const;
		std::string ToString();

	private:
		void LoadIniFile(const std::string& iniFilePath);

	};
}