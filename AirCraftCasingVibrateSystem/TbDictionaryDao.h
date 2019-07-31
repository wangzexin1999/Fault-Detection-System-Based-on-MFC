#pragma once
#include "PDDatabase.h"
class TbDictionaryDao :
	public PDDatabase
{
public:
	TbDictionaryDao();
	TbDictionaryDao(const TbDictionaryDao  & dictionary);
	~TbDictionaryDao();
public:
	PDAttribute m_dictId;
	PDAttribute m_dictName;
	PDAttribute m_dictValue;
};

