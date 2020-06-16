// File Name:     IniSettings.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#pragma once

#include "core/IniFileContents.hpp"
#include "core/Key.hpp"
#include <string>

namespace IniRW
{
	class IniSettings : public IniFileContents
	{
	private:

	public:
		IniSettings(const std::string& iniFilePath);

		std::string GetKeyValue(const std::string& sectionName, const std::string& keyName);

		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);
	};
}