// File Name:     IniSetting.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include <string>

namespace IniRW
{
	class IniSetting
	{
	private:
		bool loaded;
		std::string iniFilePath;

	public:
		IniSetting(const std::string& iniFilePath);

		bool IsLoaded() const;

	private:
		void LoadIniFile(const std::string& iniFilePath);

	};
}