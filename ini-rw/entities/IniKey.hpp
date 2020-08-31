// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "IniEntity.hpp"
#include <string>

namespace IniRW
{
	class IniKey : public IniEntity
	{
	private:
		std::string section;
		std::string name;
		std::string value;
		std::string comment;

	public:
		IniKey(const std::string& section, const std::string& name, const std::string& value, const std::string& comment);

		std::string GetSection() const;

		std::string GetName() const;

		std::string GetValue() const;

		std::string GetComment() const;
	};
}