// File Name:     IniFile.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

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

		void write_key_value(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		IniKey* get_key(const std::string& sectionName, const std::string& keyName);
	};

	std::ostream& operator<<(std::ostream& outputStream, const IniFile& iniFile);
}
