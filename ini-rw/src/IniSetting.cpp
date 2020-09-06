// File Name:     IniSetting.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../inc/IniSetting.hpp"
#include "../inc/algorithms/Parse.hpp"
#include "../inc/algorithms/Search.hpp"
#include "../inc/algorithms/Validation.hpp"
#include "../inc/entities/IniSection.hpp"
#include "../inc/entities/IniValueCommentPair.hpp"
#include <fstream>
#include <iostream>

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
					case IniEntityType::ValueCommentPair:
						{
							iniContents.push_back(new IniValueCommentPair(*static_cast<IniValueCommentPair*>(entity)));
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
				case IniEntityType::ValueCommentPair:
					{
						delete static_cast<IniValueCommentPair*>(entity);
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
			std::string currentLine, currentSectionName;

			// Read every line from the INI file
			while (std::getline(fileStream, currentLine))
			{
				if (IsValidIniSection(currentLine))
				{
					currentSectionName = ExtractSectionName(currentLine);

					iniContents.push_back(new IniSection(currentSectionName));
				}
				else if (IsValidIniKey(currentLine))
				{
					size_t equalSignIndex = currentLine.find_first_of('=');
					std::string keyName = currentLine.substr(0, equalSignIndex);
					std::string keyCommentValue = currentLine.substr(equalSignIndex + 1, currentLine.length() - 1);
					
					iniContents.push_back(new IniKey(currentSectionName, keyName, keyCommentValue));
				}
				else // It's either an INI comment, a new line, or a garbage string value
				{
					iniContents.push_back(new IniValueCommentPair(currentLine));
				}
			}

			loaded = true;
		}
	}

	void IniSetting::WriteComment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text)
	{
		if (index > iniContents.size())
		{
			throw std::out_of_range("The index was out of range.");
		}

		std::vector<IniEntity*>::iterator insertPos = iniContents.begin() + index;
		std::string comment = std::string(1, static_cast<char>(prefix)) + text;

		iniContents.insert(insertPos, new IniValueCommentPair(comment));
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
					iniContents.insert(iniContents.end(), new IniValueCommentPair("\n"));
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