/************************************************************************
文件名称： FileController.h
内容摘要： 传感器的实体类对象。对应的实现类文件为TbChannel.cpp。
************************************************************************/
#include "TbDictionary.h"
#include"TbSensor.h"
#include"TbEquipment.h"
#include"TbTestlocation.h"
#pragma once
class TbChannel
{

private:

	int m_id;
	CString m_channelCode;
	int m_collectionparasId;
	TbSensor m_sensor;

	TbDictionary m_channelStatus;
	TbDictionary m_messureType;
	CString m_channelDesc;
	TbDictionary m_windowType;
	float m_triggerMagnitude;
	TbDictionary m_triggerPolarity;
	int m_pointNum;
	TbDictionary m_coordinateSystem;
	TbDictionary m_coordinateSystemDirection;
	char m_isReference;
	TbDictionary m_engineeringUnits;
	float  m_sensitivity;
	int m_mileageRange;
	TbDictionary m_integralType;
	TbDictionary m_integralUnits;
	TbDictionary m_inputMethod;
	char m_antiAliasingFiltering;
	float m_maxFrequency;





public:
	TbChannel(int channelCode = 0);
	~TbChannel();

	void SetId(int id);
	int GetId();
	void SetChannelCode(CString channel);
	CString GetChannelCode();
	CString GetChannels();
	int GetCollectionparasId();
	void SetCollectionparasId(int collectionparasId);
	TbDictionary & GetChannelStatus();
	void SetChannelStatus(TbDictionary ChannelStatus);
	TbDictionary & GetMessureType();
	void SetMessureType(TbDictionary messureType);
	CString GetChannelDesc();
	void SetChannelDesc(CString channelDesc);
	TbDictionary & GetWindowType();
	void SetWindowType(TbDictionary windowType);
	float GetTriggerMagnitude();
	void SetTriggerMagnitude(float triggerMagnitude);
	TbDictionary & GetTriggerPolarity();
	void SetTriggerPolarity(TbDictionary triggerPolarity);
	int GetPointNum();
	void SetPointNum(int pointNum);
	TbDictionary & GetCoordinateSystem();
	void SetCoordinateSystem(TbDictionary coordinateSystem);
	TbDictionary & GetCoordinateSystemDirection();
	void SetCoordinateSystemDirection(TbDictionary coordinateSystemDirection);
	char GetIsReference();
	void SetIsReference(char isReference);
	TbDictionary & GetEngineeringUnits();
	void SetEngineeringUnits(TbDictionary engineeringUnits);
	float GetSensitivity();
	void SetSensitivity(float sensitivity);
	int GetMileageRange();
	void SetMileageRange(int mileageRange);
	TbDictionary & GetIntegralType();
	void SetIntegralType(TbDictionary integralType);
	TbDictionary & GetIntegralUnits();
	void SetIntegralUnits(TbDictionary integralUnits);
	TbDictionary & GetInputMethod();
	void SetInputMethod(TbDictionary inputMethod);
	char GetAntiAliasingFiltering();
	void SetAntiAliasingFiltering(char antiAliasingFiltering);
	float GetMaxFrequency();
	void SetMaxFrequency(float maxFrequency);


	void SetSensor(TbSensor sensor);
	TbSensor & GetSensor();


};

