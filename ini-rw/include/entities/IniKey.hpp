// File Name:     IniKey.hpp
// By:            Darian Benam (GitHub: https://github.com/BeardedFish/)
// Date:          Monday, August 31, 2020

#pragma once

#include "../enums/IniCommentPrefix.hpp"
#include "IniEntity.hpp"
#include "IniSection.hpp"
#include "IniValueCommentPair.hpp"
#include <string>

namespace inirw
{
	class IniKey : public IniEntity
	{
	private:
		IniSection* m_iniSection;
		std::string m_name;
	public:
		IniValueCommentPair ValueCommentPair;

		IniKey(IniSection* iniSection, const std::string& name, const IniValueCommentPair& valueCommentPair);

		IniEntityType get_type() const override;

		std::string to_string() const override;

		IniSection* get_section() const;

		std::string get_name() const;
	};
}
