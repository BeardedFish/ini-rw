// File Name:     IniFile.cpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#include "../include/IniFile.hpp"
#include "../include/algorithms/Parse.hpp"
#include "../include/algorithms/Search.hpp"
#include "../include/algorithms/Validation.hpp"
#include "../include/entities/IniSection.hpp"
#include "../include/entities/IniValueCommentPair.hpp"
#include <fstream>

namespace inirw
{
	IniFile::IniFile() : IniFile(true, "")
	{

	}

	IniFile::IniFile(const std::string& filePath) : IniFile(false, filePath)
	{
		load(filePath);
	}

	IniFile::IniFile(const bool loaded, const std::string& filePath) : m_loaded(loaded), m_iniFilePath(filePath)
	{

	}

	IniFile::IniFile(const IniFile& iniFile) : IniFile(iniFile.m_loaded, iniFile.m_iniFilePath)
	{
		for (size_t i = 0; i < iniFile.m_iniContents.size(); i++)
		{
			IniEntity* entity = iniFile.m_iniContents[i];

			if (!entity)
			{
				continue;
			}

			switch (entity->get_type())
			{
			case IniEntityType::Key:
				m_iniContents.push_back(new IniKey(*static_cast<IniKey*>(entity)));
				break;
			case IniEntityType::Section:
				m_iniContents.push_back(new IniSection(*static_cast<IniSection*>(entity)));
				break;
			case IniEntityType::ValueCommentPair:
				m_iniContents.push_back(new IniValueCommentPair(*static_cast<IniValueCommentPair*>(entity)));
				break;
			}
		}
	}

	IniFile::~IniFile()
	{
		clear();
	}

	IniFile::operator bool() const
	{
		return is_loaded();
	}

	IniKey* IniFile::operator[](const std::pair<std::string, std::string>& keyPair)
	{
		return get_key(keyPair.first, keyPair.second);
	}

	bool IniFile::is_loaded() const
	{
		return m_loaded;
	}

	std::string IniFile::to_string() const
	{
		std::string contents;

		for (size_t i = 0; i < m_iniContents.size(); i++)
		{
			contents += m_iniContents[i]->to_string();

			if (i < m_iniContents.size() - 1 && m_iniContents[i]->to_string() != "\n")
			{
				contents += "\n";
			}
		}

		return contents;
	}

	bool IniFile::save_changes()
	{
		return save_changes(m_iniFilePath);
	}

	bool IniFile::save_changes(const std::string& savePath)
	{
		std::ofstream fileStream(savePath);

		if (!fileStream)
		{
			return false;
		}

		fileStream << to_string();

		return true;
	}

	void IniFile::clear()
	{
		for (IniEntity*& entity : m_iniContents)
		{
			switch (entity->get_type())
			{
			case IniEntityType::Key:
				delete static_cast<IniKey*>(entity);
				break;
			case IniEntityType::Section:
				delete static_cast<IniSection*>(entity);
				break;
			case IniEntityType::ValueCommentPair:
				delete static_cast<IniValueCommentPair*>(entity);
				break;
			}
		}

		m_iniContents.clear();
	}

	void IniFile::unload()
	{
		clear();

		m_loaded = false;
		m_iniFilePath = "";
	}

	void IniFile::load(const std::string& iniFilePath)
	{
		if (is_loaded())
		{
			unload();
		}

		std::ifstream fileStream(iniFilePath);

		if (fileStream)
		{
			IniSection* currentIniSection = nullptr;
			std::string currentLine;

			// Read every line from the INI file
			while (std::getline(fileStream, currentLine))
			{
				IniEntity* entity = parse_ini_section(currentLine);

				if (entity)
				{
					currentIniSection = static_cast<IniSection*>(entity);
				}
				else
				{
					// The current line is not an INI section, try and parse it into an INI key:
					entity = parse_ini_key(currentIniSection, currentLine);

					if (!entity) // This will evaluate to true if the parse_ini_key() function failed (returns null pointer). This means that the current line is either a new line, an INI comment, or a garbage string value.
					{
						entity = new IniValueCommentPair(currentLine);
					}
				}

				m_iniContents.push_back(entity);
			}

			m_loaded = true;
		}
	}

	void IniFile::append_comment(const IniCommentPrefix& prefix, const std::string& text)
	{
		const size_t INSERT_POS = m_iniContents.size() > 0 ? m_iniContents.size() - 1 : 0; // Using ternary operator because the value will overflow if the size of the vector is 0

		insert_comment(INSERT_POS, prefix, text);
	}

	void IniFile::insert_comment(const IniCommentPrefix& prefix, const std::string& text)
	{
		insert_comment(0, prefix, text);
	}

	void IniFile::insert_comment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text)
	{
		if (index > m_iniContents.size())
		{
			throw std::out_of_range("The index was out of range.");
		}

		const std::vector<IniEntity*>::iterator INSERT_POS = m_iniContents.begin() + index;
		const std::string COMMENT = std::string(1, static_cast<char>(prefix)) + text;

		m_iniContents.insert(INSERT_POS, new IniValueCommentPair(COMMENT));
	}

	IniKey* IniFile::get_key(const std::string& keyName, bool isKeyGlobal)
	{
		size_t iniKeyIndex = find_ini_key_index(m_iniContents, keyName, isKeyGlobal);

		return iniKeyIndex != INI_NOT_FOUND
			? static_cast<IniKey*>(m_iniContents[iniKeyIndex])
			: nullptr;
	}

	IniKey* IniFile::get_key(const std::string& sectionName, const std::string& keyName)
	{
		size_t iniKeyIndex = find_ini_key_index(m_iniContents, sectionName, keyName);

		return iniKeyIndex != INI_NOT_FOUND
			? static_cast<IniKey*>(m_iniContents[iniKeyIndex])
			: nullptr;
	}

	std::ostream& operator<<(std::ostream& outputStream, const IniFile& iniFile)
	{
		outputStream << iniFile.to_string();

		return outputStream;
	}
}
