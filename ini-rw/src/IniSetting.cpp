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
				IniEntity* entity = nullptr;

				if (entity = ParseIniSection(currentLine))
				{
					currentSectionName = static_cast<IniSection*>(entity)->GetName();
				}
				else
				{
					// The current line is not an INI section, try and parse it into an INI key:
					entity = ParseIniKey(currentSectionName, currentLine);

					if (!entity) // This will evaluate to true if the ParseIniKey() function failed (returns null pointer). This means that the current line is either a new line, an INI comment, or a garbage string value.
					{
						entity = new IniValueCommentPair(currentLine);
					}
				}

				iniContents.push_back(entity);
			}

			loaded = true;
		}
	}

	void IniSetting::AppendComment(const IniCommentPrefix& prefix, const std::string& text)
	{
		const size_t INSERT_POS = iniContents.size() > 0 ? iniContents.size() - 1 : 0; // Using ternary operator because the value will overflow if the size of the vector is 0

		InsertComment(INSERT_POS, prefix, text);
	}

	void IniSetting::InsertComment(const IniCommentPrefix& prefix, const std::string& text)
	{
		InsertComment(0, prefix, text);
	}

	void IniSetting::InsertComment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text)
	{
		if (index > iniContents.size())
		{
			throw std::out_of_range("The index was out of range.");
		}

		const std::vector<IniEntity*>::iterator INSERT_POS = iniContents.begin() + index;
		const std::string COMMENT = std::string(1, static_cast<char>(prefix)) + text;

		iniContents.insert(INSERT_POS, new IniValueCommentPair(COMMENT));
	}

	void IniSetting::WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		IniKey* key = FindKey(iniContents, sectionName, keyName);

		if (key)
		{
			key->GetValueCommentPair().SetValueBeforeComment(keyValue);
		}
		else
		{
			const size_t SECTION_POS = GetSectionLocation(iniContents, sectionName);
			key = new IniKey(sectionName, keyName, keyValue);

			if (SECTION_POS != SECTION_NOT_FOUND)
			{
				const std::vector<IniEntity*>::iterator INSERT_POS = iniContents.begin() + SECTION_POS + 1;

				iniContents.insert(INSERT_POS, key);
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