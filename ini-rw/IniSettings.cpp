// File Name:     IniSettings.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, June 14, 2020

#include "IniSettings.hpp"
#include "core/algorithms/CommentAlgorithms.hpp"
#include "core/algorithms/KeyAlgorithms.hpp"
#include "core/algorithms/SectionAlgorithms.hpp"
#include <fstream>

namespace IniRW
{
	IniSettings::IniSettings(const std::string& iniFilePath)
	{
		this->loaded = false;
		this->iniFilePath = iniFilePath;

		loadIniFile();
	}

	IniSettings::~IniSettings()
	{
		// Delete every object that the IniSettings allocated to the heap
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

		loaded = false;
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

	Key* IniSettings::GetKey(const std::string& sectionName, const std::string& keyName)
	{
		return FindKey(iniContents, sectionName, keyName);
	}

	void IniSettings::WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		Key* key = FindKey(iniContents, sectionName, keyName);

		if (key != nullptr)
		{
			key->SetValue(keyValue);
		}
		else
		{
			Key* key = new Key(sectionName, keyName, keyValue);
			size_t sectionLoc = GetSectionLocation(iniContents, sectionName);

			if (sectionLoc != SECTION_NOT_FOUND)
			{
				std::vector<IniEntity>::iterator insertPos = iniContents.begin() + sectionLoc;

				iniContents.insert(insertPos, IniEntity(IniEntityType::Key, key));
			}
			else
			{
				if (!iniContents.empty())
				{
					iniContents.insert(iniContents.end(), IniEntity(IniEntityType::BlankLine));
				}

				iniContents.insert(iniContents.end(), IniEntity(IniEntityType::Section, new std::string(sectionName)));
				iniContents.insert(iniContents.end(), IniEntity(IniEntityType::Key, key));
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
				case IniEntityType::UnknownValue:
					{
						contents += *static_cast<std::string*>(iniContents[i].GetData());
					}
					break;
				case IniEntityType::Section:
					{
						contents += GetFormatted(*static_cast<std::string*>(iniContents[i].GetData()));
					}
					break;
				case IniEntityType::Key:
					{
						Key* key = static_cast<Key*>(iniContents[i].GetData());
						contents += key->GetName() + "=" + key->GetValue() + key->GetComment();
					}
					break;
			}

			if (i < iniContents.size() - 1 && iniContents[i].GetType() != IniEntityType::BlankLine)
			{
				contents += "\n";
			}
		}

		return contents;
	}

	void IniSettings::loadIniFile()
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
				else if (sectionEncountered && IsKey(line))
				{
					size_t equalSignIndex = line.find_first_of('=');

					if (equalSignIndex != std::string::npos)
					{
						std::string keyName = line.substr(0, equalSignIndex);
						std::string keyValue = line.substr(equalSignIndex + 1, line.length() - 1);
						std::string keyComment = ExtractAndRemoveComment(keyValue);

						Key* key = new Key(currentSection, keyName, keyValue, keyComment);
						iniContents.push_back(IniEntity(IniEntityType::Key, key));
					}
				}
				else // Unknown value
				{
					std::string* entityValue = new std::string(line);
					IniEntityType type;

					if (IsComment(line))
					{
						type = IniEntityType::Comment;
					}
					else if (IsSection(line))
					{
						sectionEncountered = true;
						*entityValue = currentSection = ExtractSectionName(*entityValue); // Killing two birds with one stone ;-)
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
} // End IniRW namespace