// File Name:     IniReader.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#pragma once

#include <string>
#include <vector>
#include "ReadResult.hpp"

namespace Ini
{
	constexpr char COMMENT_CHARS[] = { ';', '#' };

	class Reader
	{
	private:
		std::vector<std::string> iniFileContents;

		void readFileContents(const std::string& iniFilePath);
		bool isSection(const std::string& str);
		bool isNumber(const std::string& str);

		void lowercaseStr(std::string& str);

	public:
		Reader(const std::string& iniFilePath);

		/**
		 * Function Name:     ReadString()
		 *
		 * Brief:
		 *
		 * Parameters:        section -
		 *                    key -
		 *
		 * Return:
		 */
		ReadResult<std::string> ReadString(const std::string& section, const std::string& key);

		/**
		 * Function Name:     ReadBool()
		 *
		 * Brief:
		 *
		 * Parameters:        section -
		 *                    key -
		 *
		 * Return:
		 */
		ReadResult<bool> ReadBool(const std::string& section, const std::string& key);

		/**
		 * Function Name:     ReadInt()
		 *
		 * Brief:             
		 *
		 * Parameters:        section - 
		 *                    key - 
		 *
		 * Return:            
		 */
		ReadResult<int> ReadInt(const std::string& section, const std::string& key);
	};
}