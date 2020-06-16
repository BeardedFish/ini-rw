// File Name:     IniSettings.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#include "IniSettings.hpp"
#include "core/Comment.hpp"
#include "core/Section.hpp"
#include <fstream>

namespace IniRW
{
	IniSettings::IniSettings(const std::string& iniFilePath)
	{
		this->loaded = false;
		this->iniFilePath = iniFilePath;

		loadIniFile(iniFilePath);
	}

	IniSettings::~IniSettings()
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i].GetType() == IniEntityType::Key)
			{
				delete static_cast<Key*>(iniContents[i].GetData());
			}

			if (iniContents[i].GetType() == IniEntityType::Comment
				|| iniContents[i].GetType() == IniEntityType::Section
				|| iniContents[i].GetType() == IniEntityType::UnknownValue)
			{
				delete static_cast<std::string*>(iniContents[i].GetData());
			}
		}
	}

	bool IniSettings::IsLoaded()
	{
		return loaded;
	}

	bool IniSettings::Save()
	{
		std::ofstream fileStream(iniFilePath);

		if (!fileStream)
		{
			return false;
		}

		fileStream << ToString();

		return true;
	}


	Key* IniSettings::FindKey(const std::string& sectionName, const std::string& keyName)
	{
		for (size_t i = 0; i < iniContents.size(); i++)
		{
			if (iniContents[i].GetType() == IniEntityType::Key)
			{
				Key* key = static_cast<Key*>(iniContents[i].GetData());

				if (key->GetSection() == sectionName && key->GetName() == keyName)
				{
					return key;
				}
			}
		}

		return nullptr;
	}

	std::string IniSettings::GetKeyValue(const std::string& sectionName, const std::string& keyName)
	{
		Key* key = FindKey(sectionName, keyName);

		if (key != nullptr)
		{
			std::string* valueCopy = &key->GetValue();

			return valueCopy;
		}

		return nullptr;
	}

	void IniSettings::WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		Key* key = FindKey(sectionName, keyName);

		if (key != nullptr)
		{
			key->SetValue(keyValue);
		}
		else
		{
			for (size_t i = 0; i < iniContents.size(); i++)
			{
				if (iniContents[i].GetType() == IniEntityType::Section)
				{
					if (*static_cast<std::string*>(iniContents[i].GetData()) == sectionName)
					{
						std::vector<IniEntity>::iterator insertPos = iniContents.begin() + i;
						Key* key = new Key(sectionName, keyName, keyValue);

						iniContents.insert(insertPos, IniEntity(IniEntityType::Key, key));
					}
				}
			}
		}
	}

	std::string IniSettings::ToString()
	{
		std::string contents;

		for (size_t i = 0; i < iniContents.size(); i++)
		{
			switch (iniContents[i].GetType())
			{
				default:
				case IniEntityType::BlankLine:
					{
						contents += "\n";
					}
					break;
				case IniEntityType::Comment:
				case IniEntityType::Section:
				case IniEntityType::UnknownValue:
					{
						contents += *static_cast<std::string*>(iniContents[i].GetData()) + "\n";
					}
					break;
				case IniEntityType::Key:
					{
						Key* key = static_cast<Key*>(iniContents[i].GetData());
						contents += key->GetName() + "=" + key->GetValue() + "\n";
					}
					break;
			}
		}

		return contents;
	}

	void IniSettings::loadIniFile(const std::string& iniFilePath)
	{
		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			bool sectionEncountered = false;
			std::string currentSection;
			std::string line;

			while (std::getline(fileStream, line))
			{
				if (line.empty() || line == "\n")
				{
					iniContents.push_back(IniEntity(IniEntityType::BlankLine));
				}
				else if (sectionEncountered && Key::IsKey(line))
				{
					size_t equalSignIndex = line.find_first_of('=');

					if (equalSignIndex != std::string::npos)
					{
						std::string keyName = line.substr(0, equalSignIndex);
						std::string keyValue = line.substr(equalSignIndex + 1, line.length() - 1);

						Key* key = new Key(currentSection, keyName, keyValue);
						iniContents.push_back(IniEntity(IniEntityType::Key, key));
					}
				}
				else // Unknown value
				{
					std::string* entityValue = new std::string(line);
					IniEntityType type;

					if (Comment::IsComment(line))
					{
						type = IniEntityType::Comment;
					}
					else if (Section::IsSection(line))
					{
						sectionEncountered = true;
						currentSection = Section::ExtractSectionName(*entityValue);
						type = IniEntityType::Section;
					}
					else
					{
						type = IniEntityType::UnknownValue;
					}

					iniContents.push_back(IniEntity(type, entityValue));
				}
			}

			loaded = true;
		}
	}
}