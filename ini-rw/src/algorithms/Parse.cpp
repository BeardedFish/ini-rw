// File Name:     Parse.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#include "../../inc/algorithms/Parse.hpp"
#include "../../inc/algorithms/Validation.hpp"

namespace IniRW
{
	std::string ExtractAndRemoveComment(const std::vector<char>& commentPrefixes, std::string& value)
	{
		std::string comment;

		for (size_t i = 0; i < value.length() - 1; i++)
		{
			for (size_t j = 0; j < commentPrefixes.size(); j++)
			{
				if (value[i] != '\\' && value[i + 1] == commentPrefixes[j]) // Found the comment
				{
					// Extract the comment
					comment = value.substr(i, value.length() - 1);

					// Remove the comment from the original value
					value = value.substr(0, i);

					// Break out of the nested for loop
					i = j = value.length();
				}
			}
		}

		return comment;
	}

	std::string ExtractSectionName(const std::string& section)
	{
		if (!IsValidIniSection(section))
		{
			return section;
		}

		return section.substr(1, section.length() - 2);
	}
}