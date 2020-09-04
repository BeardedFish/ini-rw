// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../inc/IniSetting.hpp"
#include "../inc/algorithms/Parse.hpp"
#include "../inc/algorithms/Search.hpp"
#include "../inc/algorithms/Validation.hpp"
#include "../inc/entities/IniNewLine.hpp"
#include "../inc/entities/IniSection.hpp"
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
		Clear();
	}

	IniSetting::IniSetting(const IniSetting& iniSettings)
	{
		this->loaded = iniSettings.loaded;
		this->iniFilePath = iniSettings.iniFilePath;

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
					case IniEntityType::NewLine:
						{
							iniContents.push_back(new IniNewLine(*static_cast<IniNewLine*>(entity)));
						}
						break;
					case IniEntityType::Section:
						{
							iniContents.push_back(new IniSection(*static_cast<IniSection*>(entity)));
						}
						break;
					case IniEntityType::Key:
						{
							iniContents.push_back(new IniKey(*static_cast<IniKey*>(entity)));
						}
						break;
				}
			}
		}
	}

	IniSetting::operator bool() const
	{
		return IsLoaded();
	}

	std::ostream& operator<<(std::ostream& outputStream, const IniSetting& iniSettings)
	{
		outputStream << iniSettings.ToString();

		return outputStream;
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
			switch (iniContents[i]->GetType())
			{
				case IniEntityType::Comment:
					{
						const IniComment* INI_COMMENT = static_cast<IniComment*>(iniContents[i]);

						contents += INI_COMMENT->GetPrefix();
						contents += INI_COMMENT->GetText(); // NOTE: Reason I'm doing this on another line is because a char + a string don't append to each other...
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

		iniContents.clear();
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
			key = new IniKey(sectionName, keyName, keyValue, "");

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

	void IniSetting::LoadIniFile(const std::string& iniFilePath)
	{
		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			const std::vector<char> INI_COMMENT_PREFIXES = { '#', ';' };
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
					std::string keyComment = ExtractAndRemoveComment(INI_COMMENT_PREFIXES, keyValue);

					iniContents.push_back(new IniKey(currentSectionName, keyName, keyValue, keyComment));
				}
				else if (IsValidIniComment(INI_COMMENT_PREFIXES, currentLine))
				{
					IniCommentPrefix prefix = currentLine[0] == '#' ? IniCommentPrefix::Pound : IniCommentPrefix::Semicolon;
					std::string text = currentLine.substr(1, currentLine.length() - 1); // TODO: Probably trim white space...

					iniContents.push_back(new IniComment(prefix, text));
				}
			}

			loaded = true;
		}
	}
}