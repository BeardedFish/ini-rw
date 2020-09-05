// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../inc/IniSetting.hpp"
#include "../inc/algorithms/Parse.hpp"
#include "../inc/algorithms/Search.hpp"
#include "../inc/algorithms/Validation.hpp"
#include "../inc/entities/IniSection.hpp"
#include "../inc/entities/IniString.hpp"
#include <fstream>

namespace IniRW
{
	IniSetting::IniSetting() : IniSetting(true, "")
	{

	}

	IniSetting::IniSetting(const std::string& iniFilePath) : IniSetting(false, iniFilePath)
	{
		Load(iniFilePath);
	}

	IniSetting::IniSetting(const bool loaded, const std::string& iniFilePath)
	{
		this->loaded = loaded;
		this->iniFilePath = iniFilePath;
	}

	IniSetting::IniSetting(const IniSetting& iniSettings) : IniSetting(iniSettings.loaded, iniSettings.iniFilePath)
	{
		// Copy all values that are allocated to the heap
		for (size_t i = 0; i < iniSettings.iniContents.size(); i++)
		{
			IniEntity* entity = iniSettings.iniContents[i];

			if (entity)
			{
				switch (entity->GetType())
				{
					case IniEntityType::Comment:
						{
							iniContents.push_back(new IniComment(*static_cast<IniComment*>(entity)));
						}
						break;
					case IniEntityType::Key:
						{
							iniContents.push_back(new IniKey(*static_cast<IniKey*>(entity)));
						}
						break;
					case IniEntityType::Section:
						{
							iniContents.push_back(new IniSection(*static_cast<IniSection*>(entity)));
						}
						break;
					case IniEntityType::String:
						{
							iniContents.push_back(new IniString(*static_cast<IniString*>(entity)));
						}
						break;
				}
			}
		}
	}

	IniSetting::~IniSetting()
	{
		Clear();
	}

	std::ostream& operator<<(std::ostream& outputStream, const IniSetting& iniSettings)
	{
		outputStream << iniSettings.ToString();

		return outputStream;
	}

	IniSetting::operator bool() const
	{
		return IsLoaded();
	}

	IniKey* IniSetting::operator[](const std::pair<std::string, std::string>& keyPair)
	{
		return GetKey(keyPair.first, keyPair.second);
	}

	bool IniSetting::IsLoaded() const
	{
		return loaded;
	}

	std::string IniSetting::ToString() const
	{
		std::string contents;

		for (size_t i = 0; i < iniContents.size(); i++)
		{
			contents += iniContents[i]->ToString();

			if (i < iniContents.size() - 1 && iniContents[i]->ToString() != "\n")
			{
				contents += "\n";
			}
		}

		return contents;
	}

	bool IniSetting::SaveChanges()
	{
		return SaveChanges(iniFilePath);
	}

	bool IniSetting::SaveChanges(const std::string& savePath)
	{
		std::ofstream fileStream(savePath);

		if (!fileStream)
		{
			return false;
		}

		fileStream << ToString();

		return true;
	}

	void IniSetting::Clear()
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
				case IniEntityType::Section:
					{
						delete static_cast<IniSection*>(entity);
					}
					break;
				case IniEntityType::String:
					{
						delete static_cast<IniString*>(entity);
					}
					break;
			}
		}

		iniContents.clear();
	}

	void IniSetting::Unload()
	{
		Clear();

		loaded = false;
		iniFilePath = "";
	}

	void IniSetting::Load(const std::string& iniFilePath)
	{
		if (IsLoaded())
		{
			Unload();
		}

		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			const std::vector<char> INI_COMMENT_PREFIXES = { static_cast<char>(IniCommentPrefix::Pound) , static_cast<char>(IniCommentPrefix::Semicolon) };
			bool sectionEncountered = false;
			std::string currentLine, currentSectionName;

			// Read every line from the INI file
			while (std::getline(fileStream, currentLine))
			{
				if (IsValidIniSection(currentLine))
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
					std::string keyComment = ExtractAndRemoveComment(INI_COMMENT_PREFIXES, keyValue);

					if (!keyComment.empty())
					{
						IniCommentPrefix commentPrefix = static_cast<IniCommentPrefix>(keyComment[0]);
						std::string commentText = keyComment.substr(1, keyComment.length() - 1);

						iniContents.push_back(new IniKey(currentSectionName, keyName, keyValue, commentPrefix, commentText));
					}
					else
					{
						iniContents.push_back(new IniKey(currentSectionName, keyName, keyValue));
					}
				}
				else if (IsValidIniComment(INI_COMMENT_PREFIXES, currentLine))
				{
					IniCommentPrefix prefix = static_cast<IniCommentPrefix>(currentLine[0]);
					std::string text = currentLine.substr(1, currentLine.length() - 1);

					iniContents.push_back(new IniComment(prefix, text));
				}
				else // It's either a new line or some garbage string value
				{
					iniContents.push_back(new IniString(currentLine));
				}
			}

			loaded = true;
		}
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
			size_t sectionIndex = GetSectionLocation(iniContents, sectionName);
			key = new IniKey(sectionName, keyName, keyValue);

			if (sectionIndex != SECTION_NOT_FOUND)
			{
				std::vector<IniEntity*>::iterator insertPos = iniContents.begin() + sectionIndex;

				iniContents.insert(insertPos, key);
			}
			else
			{
				if (!iniContents.empty())
				{
					iniContents.insert(iniContents.end(), new IniString("\n"));
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
}