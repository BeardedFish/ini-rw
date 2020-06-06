// File Name:     Reader.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#include "Reader.hpp"
#include <fstream>

namespace Ini
{
	Reader::Reader(const std::string& iniFilePath)
	{
		readFileContents(iniFilePath);
	}

	ReadResult<std::string> Reader::ReadString(std::string section, std::string key)
	{
		// Ini files are case insensitive so lowercase the section and the key
		section = lowercaseStr(section);
		key = lowercaseStr(key);

		ReadResult<std::string> result;

		bool sectionFound = false;
		bool keyFound = false;

		for (std::string line : iniFileContents)
		{
			if (keyFound)
			{
				break;
			}

			if (line.length() == 0 || isComment(line))
			{
				continue;
			}

			if (!sectionFound) // Search for section
			{
				if (isSection(line))
				{
					if (lowercaseStr(line.substr(1, line.length() - 2)) == section)
					{
						sectionFound = true;
					}
				}
			}
			else // Search for key
			{
				if (isSection(line))
				{
					break;
				}

				int equalSignIndex = line.find_first_of('=');

				if (equalSignIndex != std::string::npos)
				{
					if (lowercaseStr(line.substr(0, equalSignIndex)) == key)
					{
						result.ConvertedValue = line.substr(equalSignIndex + 1, line.length() - 1);
						result.Success = true;

						cleanValue(result.ConvertedValue);

						keyFound = true;
					}
				}
			}
		}

		return result;
	}

	ReadResult<bool> Reader::ReadBool(const std::string& section, const std::string& key)
	{
		ReadResult<std::string> strKeyValue = ReadString(section, key);
		ReadResult<bool> result;

		lowercaseStr(strKeyValue.ConvertedValue);

		if (strKeyValue.ConvertedValue == "true" || strKeyValue.ConvertedValue == "false")
		{
			result.ConvertedValue = strKeyValue.ConvertedValue == "true";
		}

		return result;
	}

	ReadResult<int> Reader::ReadInt(const std::string& section, const std::string& key)
	{
		ReadResult<std::string> strKeyValue = ReadString(section, key);
		ReadResult<int> result;

		try
		{
			result.ConvertedValue = stoi(strKeyValue.ConvertedValue);
			result.Success = true;
		}
		catch (const std::exception&)
		{
			result.Success = false;
		}

		return result;
	}

	std::string Reader::ToString()
	{
		if (iniFileContents.size() > 0)
		{
			std::string fileContents;

			for (size_t i = 0; i < iniFileContents.size(); i++)
			{
				fileContents += iniFileContents[i] + (i == iniFileContents.size() - 1 ? "" : "\n");
			}

			return fileContents;
		}

		return nullptr;
	}

	void Reader::readFileContents(const std::string& iniFilePath)
	{
		std::ifstream fileReader(iniFilePath);

		if (!fileReader)
		{
			throw std::exception("Unable to read the file contents.");
		}

		std::string line;
		while (std::getline(fileReader, line))
		{
			iniFileContents.push_back(line);
		}
	}

	bool Reader::isComment(const std::string& str)
	{
		if (str.length() >= 1)
		{
			for (size_t i = 0; i < COMMENT_PREFIXES.size(); i++)
			{
				if (str[0] == COMMENT_PREFIXES[i])
				{
					return true;
				}
			}
		}

		return false;
	}

	bool Reader::isSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == '[' && str[str.length() - 1] == ']';
	}

	bool Reader::isNumber(const std::string& str)
	{
		return true;
	}

	std::string Reader::lowercaseStr(const std::string& str)
	{
		std::string lowStr;

		for (size_t i = 0; i < str.length(); i++)
		{
			lowStr += tolower(str[i]);
		}

		return lowStr;
	}

	void Reader::cleanValue(std::string& val)
	{
		// Remove the comment from the value (if there is one)
		for (size_t i = 0; i < val.length() - 1; i++)
		{
			for (size_t j = 0; j < COMMENT_PREFIXES.size(); j++)
			{
				if (val[i] != '\\' && val[i + 1] == COMMENT_PREFIXES[j]) // Found the comment
				{
					val = val.substr(0, i);

					// Break out of the nested for loop
					i = j = val.length();
				}
			}
		}

		// Replace all escape characters with there actual values
		// I will implement later... :P
	}
}