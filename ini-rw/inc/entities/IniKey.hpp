// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "../enums/IniCommentPrefix.hpp"
#include "IniEntity.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace IniRW
{
	class IniKey : public IniEntity
	{
	private:
		std::string m_section;
		std::string m_name;
		IniValueCommentPair m_valueCommentPair;
	public:
		IniKey(const std::string& section, const std::string& name, const IniValueCommentPair& valueCommentPair);

		IniEntityType GetType() const override;

		std::string ToString() const override;

		std::string GetSection() const;

		std::string GetName() const;

		IniValueCommentPair GetValueCommentPair() const;
	};
}