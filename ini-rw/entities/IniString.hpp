// File Name:     IniString.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Sunday, August 30, 2020

#pragma once

#include "IniEntity.hpp"
#include "../enums/IniEntityType.hpp"
#include <string>

namespace IniRW
{
	class IniString : public IniEntity
	{
	private:
		std::string text;

	public:
		IniString(IniEntityType type, const std::string& text);

		std::string GetText() const;

	};
}