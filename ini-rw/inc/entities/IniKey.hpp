// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "IniEntity.hpp"
#include "../enums/IniCommentPrefix.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace IniRW
{
	class IniKey : public IniEntity
	{
	private:
		std::string section;
		std::string name;
		IniValueCommentPair valueCommentPair;

	public:
		IniKey(const std::string& section, const std::string& name, const std::string& value);

		IniEntityType GetType() override;

		std::string ToString() const override;

		std::string GetSection() const;

		std::string GetName() const;

		IniValueCommentPair GetValueCommentPair() const;
	};
}