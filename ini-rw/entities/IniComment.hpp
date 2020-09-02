// File Name:     IniString.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "IniEntity.hpp"
#include <string>

namespace IniRW
{
	class IniComment : public IniEntity
	{
	private:
		char prefix;
		std::string text;

	public:
		IniComment();

		IniComment(const char prefix, const std::string& text);

		virtual IniEntityType GetType();

		std::string GetText() const;
	};
}