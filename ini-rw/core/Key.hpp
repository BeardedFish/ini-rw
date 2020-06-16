// File Name:     Key.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Saturday, June 13, 2020

#pragma once

#include <string>
#include <vector>

namespace IniRW
{
	class Key
	{
	private:
		std::string section;
		std::string name;
		std::string value;
		std::string comment;

	public:
		Key(const std::string& section, const std::string& name, const std::string& value);
		Key(const std::string& section, const std::string& name, const std::string& value, const std::string& comment);

		std::string GetSection();
		std::string GetName();
		std::string GetValue();
		std::string GetComment();
		
		void SetValue(const std::string& newValue);
	};
} // End IniRW namespace