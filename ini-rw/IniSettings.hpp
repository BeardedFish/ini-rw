// File Name:     IniSettings.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

#include "core/IniEntity.hpp"
#include "core/Key.hpp"
#include "return_types/ReadResult.hpp"
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
		IniSettings(const std::string& iniFilePath);
		~IniSettings();

		bool IsLoaded();
		bool Save();

		ReadResult<std::string> GetKeyValue(const std::string& sectionName, const std::string& keyName);

		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		std::string ToString();

	private:
		void loadIniFile(const std::string& iniFilePath);

	};
}