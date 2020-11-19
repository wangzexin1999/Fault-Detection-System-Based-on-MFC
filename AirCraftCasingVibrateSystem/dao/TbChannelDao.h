#pragma once
#include "PDDatabase.h"
#include "TbChannel.h"
class TbChannelDao :
	public PDDatabase
{
public:
	TbChannelDao();
	TbChannelDao(const TbChannelDao & channel);
	~TbChannelDao();

	PDAttribute m_id;
	PDAttribute m_channelCode;
	PDAttribute m_channelDesc;
	PDAttribute m_collectionparasId;
	PDAttribute m_sersorStatus;
	PDAttribute m_messureType;
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
	PDAttribute m_sensorId;

	void SetTableFieldValues(TbChannel channel);

	void GetTableFieldValues(TbChannel &channel);

	bool SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

