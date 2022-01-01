// File Name:     IniSetting.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "entities/IniEntity.hpp"
#include "entities/IniKey.hpp"
#include <string>
#include <vector>

namespace inirw
{
	class IniSetting
	{
	private:
		bool m_loaded;
		std::string m_iniFilePath;
		std::vector<IniEntity*> m_iniContents;

	public:
		IniSetting();

		IniSetting(const std::string& iniFilePath);

		IniSetting(const IniSetting& iniSettings);

	private:
		IniSetting(const bool loaded, const std::string& iniFilePath);

	public:
		~IniSetting();

		friend std::ostream& operator<<(std::ostream& outputStream, const IniSetting& iniSettings);

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
}
