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
		load(iniFilePath);
	}

	IniSetting::IniSetting(const bool loaded, const std::string& iniFilePath) : m_loaded(loaded), m_iniFilePath(iniFilePath)
	{

	}

	IniSetting::IniSetting(const IniSetting& iniSettings) : IniSetting(iniSettings.m_loaded, iniSettings.m_iniFilePath)
	{
		// Copy all values that are allocated to the heap
		for (size_t i = 0; i < iniSettings.m_iniContents.size(); i++)
		{
			IniEntity* entity = iniSettings.m_iniContents[i];

			if (entity)
			{
				switch (entity->get_type())
				{
					case IniEntityType::Key:
						{
							m_iniContents.push_back(new IniKey(*static_cast<IniKey*>(entity)));
						}
						break;
					case IniEntityType::Section:
						{
							m_iniContents.push_back(new IniSection(*static_cast<IniSection*>(entity)));
						}
						break;
					case IniEntityType::ValueCommentPair:
						{
							m_iniContents.push_back(new IniValueCommentPair(*static_cast<IniValueCommentPair*>(entity)));
						}
						break;
				}
			}
		}
	}

	IniSetting::~IniSetting()
	{
		clear();
	}

	std::ostream& operator<<(std::ostream& outputStream, const IniSetting& iniSettings)
	{
		outputStream << iniSettings.to_string();

		return outputStream;
	}

	IniSetting::operator bool() const
	{
		return is_loaded();
	}

	IniKey* IniSetting::operator[](const std::pair<std::string, std::string>& keyPair)
	{
		return get_key(keyPair.first, keyPair.second);
	}

	bool IniSetting::is_loaded() const
	{
		return m_loaded;
	}

	std::string IniSetting::to_string() const
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

	bool IniSetting::save_changes()
	{
		return save_changes(m_iniFilePath);
	}

	bool IniSetting::save_changes(const std::string& savePath)
	{
		std::ofstream fileStream(savePath);

		if (!fileStream)
		{
			return false;
		}

		fileStream << to_string();

		return true;
	}

	void IniSetting::clear()
	{
		// Delete all INI entities allocated to the heap
		for (IniEntity*& entity : m_iniContents)
		{
			switch (entity->get_type())
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

		m_iniContents.clear();
	}

	void IniSetting::unload()
	{
		clear();

		m_loaded = false;
		m_iniFilePath = "";
	}

	void IniSetting::load(const std::string& iniFilePath)
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

	void IniSetting::append_comment(const IniCommentPrefix& prefix, const std::string& text)
	{
		const size_t INSERT_POS = m_iniContents.size() > 0 ? m_iniContents.size() - 1 : 0; // Using ternary operator because the value will overflow if the size of the vector is 0

		insert_comment(INSERT_POS, prefix, text);
	}

	void IniSetting::insert_comment(const IniCommentPrefix& prefix, const std::string& text)
	{
		insert_comment(0, prefix, text);
	}

	void IniSetting::insert_comment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text)
	{
		if (index > m_iniContents.size())
		{
			throw std::out_of_range("The index was out of range.");
		}

		const std::vector<IniEntity*>::iterator INSERT_POS = m_iniContents.begin() + index;
		const std::string COMMENT = std::string(1, static_cast<char>(prefix)) + text;

		m_iniContents.insert(INSERT_POS, new IniValueCommentPair(COMMENT));
	}

	void IniSetting::write_key_value(const std::string& sectionName, const std::string& keyName, const std::string& keyValue)
	{
		size_t iniKeyIndex = find_key_index(m_iniContents, sectionName, keyName);

		if (iniKeyIndex != INI_NOT_FOUND)
		{
			static_cast<IniKey*>(m_iniContents[iniKeyIndex])->ValueCommentPair.set_value_before_comment(keyValue);
		}
		else
		{
			size_t sectionIndex = get_section_location(m_iniContents, sectionName);

			if (sectionIndex != INI_NOT_FOUND)
			{
				m_iniContents.insert(m_iniContents.begin() + sectionIndex + 1, new IniKey(static_cast<IniSection*>(m_iniContents[sectionIndex]), keyName, keyValue));
			}
			else
			{
				if (!m_iniContents.empty())
				{
					m_iniContents.insert(m_iniContents.end(), new IniValueCommentPair("\n"));
				}

				IniSection* iniSection = new IniSection(sectionName);

				m_iniContents.insert(m_iniContents.end(), iniSection);
				m_iniContents.insert(m_iniContents.end(), new IniKey(iniSection, keyName, keyValue));
			}
		}
	}

	IniKey* IniSetting::get_key(const std::string& sectionName, const std::string& keyName)
	{
		size_t iniKeyIndex = find_key_index(m_iniContents, sectionName, keyName);

		if (iniKeyIndex != INI_NOT_FOUND)
		{
			return static_cast<IniKey*>(m_iniContents[iniKeyIndex]);
		}

		return nullptr;
	}
}
