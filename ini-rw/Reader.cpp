// File Name:     Reader.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Tuesday, June 2, 2020

#include <fstream>
#include "Reader.hpp"

namespace Ini
{
	Reader::Reader(const std::string& iniFilePath)
	{
		readFileContents(iniFilePath);
	}

	ReadResult<std::string> Reader::ReadString(const std::string& section, const std::string& key)
	{
		ReadResult<std::string> result;

		bool sectionFound = false;
		bool keyFound = false;

		for (std::string line : iniFileContents)
		{
			if (keyFound)
			{
				break;
			}

			if (line.length() == 0)
			{
				continue;
			}

			if (!sectionFound)
			{
				if (isSection(line))
				{
					if (line.substr(1, line.length() - 2) == section)
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
					if (line.substr(0, equalSignIndex) == key)
					{
						result.ConvertedValue = line.substr(equalSignIndex + 1, line.length() - 1);
						result.Success = true;

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

		if (strKeyValue.Success)
		{
			try
			{
				result.ConvertedValue = stoi(strKeyValue.ConvertedValue);
				result.Success = true;
			}
			catch (const std::exception&)
			{
				// NOTE: This catch block is left blank on purpose because the result boolean is set to false by default
			}
		}

		return result;
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

	bool Reader::isSection(const std::string& str)
	{
		return str.length() >= 2 && str[0] == '[' && str[str.length() - 1] == ']';
	}

	bool Reader::isNumber(const std::string& str)
	{
		return true;
	}

	void Reader::lowercaseStr(std::string& str)
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
	}
}