#include "stdafx.h"
#include "TbTeststateDao.h"
TbTeststateDao::TbTeststateDao()
{
	this->m_strTableName = "tb_teststate";
	m_key = &m_stateId;
	SetVectorAndField("state_id", "int", m_stateId);
	SetVectorAndField("state_name", "CString", m_stateName);
	SetVectorAndField("speed", "double", m_speed);
	SetVectorAndField("acceleration", "double", m_acceleration);
	SetVectorAndField("product_type_id", "int", m_productTypeId);
}
TbTeststateDao::TbTeststateDao(const TbTeststateDao &teststate)
{
	this->m_strTableName = "tb_teststate";
	m_key = &m_stateId;
	SetVectorAndField("state_id", "int", m_stateId);
	SetVectorAndField("state_name", "CString", m_stateName);
	SetVectorAndField("speed", "double", m_speed);
	SetVectorAndField("acceleration", "double", m_acceleration);
	SetVectorAndField("product_type_id", "int", m_productTypeId);
	operator = (teststate);
}
TbTeststateDao::~TbTeststateDao()
{

}

void TbTeststateDao::SetTableFieldValues(TbTeststate teststate)
{
	this->m_stateId.SetValue(teststate.GetStateId());
	this->m_stateName.SetValue(teststate.GetStateName());
	this->m_speed.SetValue(teststate.GetSpeed());
	this->m_acceleration.SetValue(teststate.GetAcceleration());
	this->m_productTypeId.SetValue(teststate.GetProductType().GetId());
}
void TbTeststateDao::GetTableFieldValues(TbTeststate &teststate)
{
	teststate.SetStateId(m_stateId.GetInt());
	teststate.SetStateName(m_stateName.m_strValue);
	teststate.SetSpeed(m_speed.GetFloatOrDouble());
	teststate.SetAcceleration(m_acceleration.GetFloatOrDouble());
	teststate.GetProductType().SetId(m_productTypeId.GetInt());
}

bool TbTeststateDao::SelectObjectsByCondition(vector<TbTeststateDao> &selectedValueVector, CString strSqlQueryWhere )
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbTeststateDao::SelectObjectsByCondition(vector<TbTeststateDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere )
{
	vector<CString> tmpDetectedObjecIDs;
	TbTeststateDao teststate;
	if (teststate.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			teststate.m_stateId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (teststate.SelectByKey())
			{
				selectedValueVector.push_back(teststate);
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
