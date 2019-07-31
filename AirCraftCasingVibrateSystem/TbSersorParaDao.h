#pragma once
#include "PDDatabase.h"
class TbSersorParaDao :
	public PDDatabase
{
public:
	TbSersorParaDao();
	TbSersorParaDao(const TbSersorParaDao &sersorPara);
	~TbSersorParaDao();

	PDAttribute m_sensorParaId;
	PDAttribute m_projectId;
	PDAttribute m_sersorId;
	PDAttribute m_sersorStatus;
	PDAttribute m_messureType;
	PDAttribute m_sensorDesc;
	PDAttribute m_windowType;
	PDAttribute m_triggerMagnitude;
	PDAttribute m_triggerPolarity;
	PDAttribute m_pointNum;
	PDAttribute m_coordinateSystem;
	PDAttribute m_coordinateSystemDirection;
	PDAttribute m_isReference;
	PDAttribute m_engineeringUnits;
	PDAttribute m_sensitivity;
	PDAttribute m_mileageRange;
	PDAttribute m_integralType;
	PDAttribute m_integralUnits;
	PDAttribute m_inputMethod;
	PDAttribute m_antiAliasingFiltering;
	PDAttribute m_maxFrequency;
	PDAttribute m_isUsed;
	


	bool SelectObjectsByCondition(vector<TbSersorParaDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSersorParaDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

