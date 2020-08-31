// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniSetting.hpp"
#include "entities//algorithms/IniCommentAlgorithms.hpp"
#include "entities/algorithms/IniKeyAlgorithms.hpp"
#include "entities/algorithms/IniSectionAlgorithms.hpp"
#include <fstream>

namespace IniRW
{
	IniSetting::IniSetting(const std::string& iniFilePath)
	{
		this->loaded = false;
		this->iniFilePath = iniFilePath;

		LoadIniFile(iniFilePath);
	}

	bool IniSetting::IsLoaded() const
	{
		return loaded;
	}

	std::string IniSetting::ToString()
	{
		std::string contents;

		for (size_t i = 0; i < iniContents.size(); i++)
		{
			switch (iniContents[i]->GetType())
			{
				default:
				case IniEntityType::Comment:
				case IniEntityType::NewLine:
				case IniEntityType::Section:
				case IniEntityType::UnknownValue:
				{
					if (iniContents[i]->GetType() == IniEntityType::Section)
					{
						contents += "[ " + static_cast<IniString*>(iniContents[i])->GetText() + "]";
					}
					else
					{
						contents += static_cast<IniString*>(iniContents[i])->GetText();
					}
				}
				break;
				case IniEntityType::Key:
				{
					IniKey* key = static_cast<IniKey*>(iniContents[i]);
					contents += key->GetName() + "=" + key->GetValue() + key->GetComment();
				}
				break;
			}

			if (i < iniContents.size() - 1 && iniContents[i]->GetType() != IniEntityType::NewLine)
			{
				contents += "\n";
			}
		}

		return contents;
	}

	void IniSetting::LoadIniFile(const std::string& iniFilePath)
	{
		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			bool sectionEncountered = false;
			std::string currentSectionName;
			std::string currentLine;

			// Read every line from the INI file
			while (std::getline(fileStream, currentLine))
			{
				if (sectionEncountered && IsValidIniKey(currentLine))
				{
					size_t equalSignIndex = currentLine.find_first_of('=');
					std::string keyName = currentLine.substr(0, equalSignIndex);
					std::string keyValue = currentLine.substr(equalSignIndex + 1, currentLine.length() - 1);
					std::string keyComment = ExtractAndRemoveComment(keyValue);

					iniContents.push_back(new IniKey(currentSectionName, keyName, keyValue, keyComment));
				}
				else
				{
					IniStringType type;
					std::string entityValue = currentLine;

					if (IsValidIniComment(currentLine))
					{
						type = IniStringType::Comment;
					}
					else if (IsValidIniSection(currentLine))
					{
						sectionEncountered = true;
						currentSectionName = entityValue = ExtractSectionName(currentLine);
						type = IniStringType::Section;
					}
					else if (currentLine.empty() || currentLine == "\n")
					{
						type = IniStringType::NewLine;
						entityValue = "\n";
					}
					else // Unknown/garbage value
					{
						type = IniStringType::UnknownValue;
					}

					iniContents.push_back(new IniString(type, entityValue));
				}
			}

			loaded = true;
		}
	}
}