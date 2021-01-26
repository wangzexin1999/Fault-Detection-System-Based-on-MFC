#pragma once
#include "PDDatabase.h"
#include "TbCollectionparas.h"

class TbCollectionparasDao :
	public PDDatabase
{
public:
	TbCollectionparasDao();
	TbCollectionparasDao(const TbCollectionparasDao &Collectionparas);
	~TbCollectionparasDao();

	bool SelectObjectsByCondition(vector<TbCollectionparasDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbCollectionparasDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
	void GetTableFieldValues(TbCollectionparas &collectionparas);
	void SetTableFieldValues(TbCollectionparas collectionparas);
public:
	PDAttribute m_id;
	PDAttribute m_equipmentId;
	PDAttribute m_sampleFrequency;
	PDAttribute m_collectionMethod;
	PDAttribute m_triggerMethod;
	PDAttribute m_sampleBatch;

	PDAttribute m_dataBlocks;
	PDAttribute m_delayBlocks;
	PDAttribute m_triggerTimes;
	PDAttribute m_line;

};

