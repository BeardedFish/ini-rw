// File Name:     IniSection.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Wednesday, September 2, 2020

#pragma once

#include "IniEntity.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace IniRW
{
	class IniSection : public IniEntity
	{
	private:
		std::string leadingWhitespace;
		std::string name;
		IniValueCommentPair extraData;

	public:
		IniSection(const std::string& iniLine);

		IniEntityType GetType() override;

		std::string ToString() const override;

		std::string GetName() const;
	};
}