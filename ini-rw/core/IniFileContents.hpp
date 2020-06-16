// File Name:     IniFileContents.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#pragma once

#include "IniEntity.hpp"
#include "Key.hpp"
#include <string>
#include <vector>

namespace IniRW
{
	class IniFileContents
	{
	private:
		std::string iniFilePath;
		bool loaded;

	protected:
		std::vector<IniEntity> iniContents;

	public:
		~IniFileContents();
		IniFileContents(const std::string& iniFilePath);

		bool IsLoaded();
		bool Save();

		std::string ToString();

	protected:
		Key* FindKey(const std::string& sectionName, const std::string& keyName);

	private:
		void loadIniFile(const std::string& iniFilePath);

		bool isComment(const std::string& str);

	};
}