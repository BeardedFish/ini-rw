// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "IniSetting.hpp"
#include "algorithms/IniCommentAlgorithms.hpp"
#include "algorithms/IniKeyAlgorithms.hpp"
#include "algorithms/IniSectionAlgorithms.hpp"
#include "entities/IniNewLine.hpp"
#include "entities/IniSection.hpp"
#include <fstream>

namespace IniRW
{
	IniSetting::IniSetting(const std::string& iniFilePath)
	{
		this->loaded = false;
		this->iniFilePath = iniFilePath;

		LoadIniFile(iniFilePath);
	}

	IniSetting::~IniSetting()
	{
		// Delete all INI entities allocated to the heap
		for (IniEntity*& entity : iniContents)
		{
			switch (entity->GetType())
			{
				case IniEntityType::Comment:
					{
						delete static_cast<IniComment*>(entity);
					}
					break;
				case IniEntityType::Key:
					{
						delete static_cast<IniKey*>(entity);
					}
					break;
				case IniEntityType::NewLine:
					{
						delete static_cast<IniNewLine*>(entity);
					}
					break;
				case IniEntityType::Section:
					{
						delete static_cast<IniSection*>(entity);
					}
					break;
			}
		}
	}

	bool IniSetting::IsLoaded() const
	{
		return loaded;
	}

	bool IniSetting::SaveChanges()
	{
		std::ofstream fileStream(iniFilePath);

		if (!fileStream)
		{
			return false;
		}

		fileStream << ToString();

		return true;
	}

	void IniSetting::WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		IniKey* key = FindKey(iniContents, sectionName, keyName);

		if (key)
		{
			key->SetValue(keyValue);
		}
		else
		{
			IniKey* key = new IniKey(sectionName, keyName, keyValue, "");
			size_t sectionIndex = GetSectionLocation(iniContents, sectionName);

			if (sectionIndex != SECTION_NOT_FOUND)
			{
				std::vector<IniEntity*>::iterator insertPos = iniContents.begin() + sectionIndex;

				iniContents.insert(insertPos, key);
			}
			else
			{
				if (!iniContents.empty())
				{
					iniContents.insert(iniContents.end(), new IniNewLine());
				}

				iniContents.insert(iniContents.end(), new IniSection(sectionName));
				iniContents.insert(iniContents.end(), key);
			}
		}
	}

	IniKey* IniSetting::GetKey(const std::string& sectionName, const std::string& keyName)
	{
		return FindKey(iniContents, sectionName, keyName);
	}

	std::string IniSetting::ToString()
	{
		std::string contents;

		for (size_t i = 0; i < iniContents.size(); i++)
		{
			switch (iniContents[i]->GetType())
			{
				case IniEntityType::Comment:
				{
					contents += static_cast<IniComment*>(iniContents[i])->GetText();
				}
				break;
				case IniEntityType::NewLine:
					{
						contents += static_cast<IniNewLine*>(iniContents[i])->GetValue();
					}
					break;
				case IniEntityType::Section:
					{
						contents += static_cast<IniSection*>(iniContents[i])->GetName();
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
				if (currentLine.empty() || currentLine == "\n")
				{
					iniContents.push_back(new IniNewLine());
				}
				else if (IsValidIniSection(currentLine))
				{
					sectionEncountered = true;
					currentSectionName = ExtractSectionName(currentLine);

					iniContents.push_back(new IniSection(currentSectionName));
				}
				else if (sectionEncountered && IsValidIniKey(currentLine))
				{
					size_t equalSignIndex = currentLine.find_first_of('=');
					std::string keyName = currentLine.substr(0, equalSignIndex);
					std::string keyValue = currentLine.substr(equalSignIndex + 1, currentLine.length() - 1);
					std::string keyComment = ExtractAndRemoveComment(keyValue);

					iniContents.push_back(new IniKey(currentSectionName, keyName, keyValue, keyComment));
				}
				else if (IsValidIniComment(currentLine))
				{
					iniContents.push_back(new IniComment(';', currentLine));
				}
			}

			loaded = true;
		}
	}
}