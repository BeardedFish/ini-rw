// File Name:     IniSetting.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "entities/IniEntity.hpp"
#include "entities/IniKey.hpp"
#include <string>
#include <vector>

namespace IniRW
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

		bool IsLoaded() const;

		std::string ToString() const;

		bool SaveChanges();

		bool SaveChanges(const std::string& savePath);

		void Clear();

		void Unload();

		void Load(const std::string& iniFilePath);

		void AppendComment(const IniCommentPrefix& prefix, const std::string& text);

		void InsertComment(const IniCommentPrefix& prefix, const std::string& text);

		void InsertComment(const size_t& index, const IniCommentPrefix& prefix, const std::string& text);

		void WriteKeyValue(const std::string& sectionName, const std::string& keyName, const std::string& keyValue);

		IniKey* GetKey(const std::string& sectionName, const std::string& keyName);
	};
}