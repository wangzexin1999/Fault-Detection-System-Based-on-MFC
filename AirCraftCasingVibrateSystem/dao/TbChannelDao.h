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
	PDAttribute m_messureType;//测量行
	PDAttribute m_windowType;
	PDAttribute m_triggerMagnitude;
	PDAttribute m_triggerPolarity;
	PDAttribute m_pointNum;
	PDAttribute m_coordinateSystem;
	PDAttribute m_coordinateSystemDirection;
	PDAttribute m_isReference;
	PDAttribute m_engineeringUnits;
	PDAttribute m_sensitivity;//灵敏度
	PDAttribute m_fullvalue;//满度量程
	PDAttribute m_integralType;
	PDAttribute m_integralUnits;
	PDAttribute m_inputMode;//输入方式
	PDAttribute m_antiAliasingFiltering;
	PDAttribute m_upFreq;//上限频率
	PDAttribute m_sensorId;
	PDAttribute m_elcpressure;//电压测量类型
	PDAttribute m_projectId;//电压测量类型
	void SetTableFieldValues(TbChannel channel);

	void GetTableFieldValues(TbChannel &channel);

	bool SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

