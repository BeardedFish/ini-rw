// File Name:     IniFile.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "../include/algorithms/Search.hpp"
#include "entities/IniEntity.hpp"
#include "entities/IniKey.hpp"
#include <string>
#include <vector>

namespace inirw
{
	class IniFile
	{
	private:
		bool m_loaded;
		std::string m_iniFilePath;
		std::vector<IniEntity*> m_iniContents;
	public:
		IniFile();
		IniFile(const std::string& filePath);
		IniFile(const IniFile& iniFile);
	private:
		IniFile(const bool loaded, const std::string& filePath);
	public:
		~IniFile();

		operator bool() const;

		IniKey* operator[](const std::pair<std::string, std::string>& keyPair);

		bool is_loaded() const;

		std::string to_string() const;

		bool save_changes();

		bool save_changes(const std::string& savePath);

		void clear();

		void unload();

		void load(const std::string& iniFilePath);

		void append_comment(const IniCommentPrefix& prefix, const std::string& text);

		void insert_comment(const IniCommentPrefix& prefix, const std::string& text);

		void insert_comment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text);

		template<typename KeyValueType>
		void write_key_value(const std::string& sectionName, const std::string& keyName, const KeyValueType& keyValue)
		{
			size_t iniKeyIndex = find_key_index(m_iniContents, sectionName, keyName);
			std::string keyValueString;

			if constexpr (std::is_same<KeyValueType, std::string>::value)
			{
				keyValueString = keyValue;
			}
			else if constexpr (std::is_same<KeyValueType, char>::value)
			{
				keyValueString = std::string(1, keyValue);
			}
			else
			{
				keyValueString = std::to_string(keyValue);
			}

			if (iniKeyIndex != INI_NOT_FOUND)
			{
				static_cast<IniKey*>(m_iniContents[iniKeyIndex])->ValueCommentPair.set_value(keyValueString);
			}
			else
			{
				size_t sectionIndex = get_section_location(m_iniContents, sectionName);

				if (sectionIndex != INI_NOT_FOUND)
				{
					m_iniContents.insert(m_iniContents.begin() + sectionIndex + 1, new IniKey(static_cast<IniSection*>(m_iniContents[sectionIndex]), keyName, keyValueString));
				}
				else
				{
					if (!m_iniContents.empty())
					{
						m_iniContents.insert(m_iniContents.end(), new IniValueCommentPair("\n"));
					}

					IniSection* iniSection = new IniSection(sectionName);

					m_iniContents.insert(m_iniContents.end(), iniSection);
					m_iniContents.insert(m_iniContents.end(), new IniKey(iniSection, keyName, keyValueString));
				}
			}
		}

		IniKey* get_key(const std::string& sectionName, const std::string& keyName);
	};

	std::ostream& operator<<(std::ostream& outputStream, const IniFile& iniFile);
}
