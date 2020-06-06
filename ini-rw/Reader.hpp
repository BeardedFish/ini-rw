// File Name:     IniReader.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#pragma once

#include "ReadResult.hpp"
#include <string>
#include <vector>

namespace Ini
{
	const std::vector<char> COMMENT_PREFIXES = { ';', '#' };

	class Reader
	{
	private:
		std::vector<std::string> iniFileContents;

		void readFileContents(const std::string& iniFilePath);
		
		bool isComment(const std::string& str);
		bool isSection(const std::string& str);
		bool isNumber(const std::string& str);

		std::string lowercaseStr(const std::string& str);

		void cleanValue(std::string& val);

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
		ReadResult<std::string> ReadString(std::string section, std::string key);

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
		
		/**
		 * Function Name:     ToString()
		 *
		 * Brief:
		 *
		 * Parameters:        None.
		 *
		 * Return:
		 */
		std::string ToString();
	};
}