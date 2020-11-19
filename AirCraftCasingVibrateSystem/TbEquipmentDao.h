#pragma once
#include "PDDatabase.h"
#include "TbEquipment.h"
using namespace std;
class TbEquipmentDao :public PDDatabase
{
public:
	TbEquipmentDao();
	TbEquipmentDao(const TbEquipmentDao &equipment);
	~TbEquipmentDao();

public:
	PDAttribute m_equipmentId;
	PDAttribute m_ip;
	PDAttribute m_createTime;
	PDAttribute m_status;

	void SetTableFieldValues(TbEquipment equipment);
	void GetTableFieldValues(TbEquipment &equipment);

	bool SelectObjectsByCondition(vector<TbEquipmentDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbEquipmentDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere );

};