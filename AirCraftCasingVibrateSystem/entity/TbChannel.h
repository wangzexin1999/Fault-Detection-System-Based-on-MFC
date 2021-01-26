/************************************************************************
�ļ����ƣ� FileController.h
����ժҪ�� ��������ʵ������󡣶�Ӧ��ʵ�����ļ�ΪTbChannel.cpp��
************************************************************************/
#include "TbDictionary.h"
#include"TbSensor.h"
#include"TbEquipment.h"
#include"TbTestlocation.h"
#include <utility>
#include <list>
#pragma once
class TbChannel
{

private:

	int m_id;//ͨ��ID
	CString m_channelCode;//ͨ�����
	TbSensor m_sensor;//��Ӧ������

	std::pair<int,CString> m_fullvalue;//��������
	std::pair<int, CString> m_upFreq;//����Ƶ��
	std::pair<int, CString> m_inputMode;//���뷽ʽ
	float m_sensitivity;//������
	std::pair<int, CString> m_elcpressure;//��ѹ������Χ
	std::pair<int, CString> m_messureType;//��������
	
	TbDictionary m_channelStatus;
	int m_collectionparasId;
	CString m_channelDesc;
	TbDictionary m_windowType;
	float m_triggerMagnitude;
	TbDictionary m_triggerPolarity;
	int m_pointNum;
	TbDictionary m_coordinateSystem;
	TbDictionary m_coordinateSystemDirection;
	char m_isReference;
	TbDictionary m_engineeringUnits;
	TbDictionary m_integralType;
	TbDictionary m_integralUnits;
	char m_antiAliasingFiltering;
	int m_projectId;
	

public:
	TbChannel(int channelCode = 0);
	~TbChannel();

	void SetId(int id);
	int GetId();
	void SetChannelCode(CString channel);
	CString GetChannelCode();

	//������
	float GetSensitivity();
	void SetSensitivity(float sensitivity);
	//��������
	std::pair<int, CString> GetFullValue();
	void SetFullValue(std::pair<int, CString> fullvalue);

	//���뷽ʽ
	std::pair<int, CString>  GetInputMode();
	void SetInputMode(std::pair<int, CString> inputMethod);

	//����Ƶ��
	std::pair<int, CString> GetUpFreq();
	void SetUpFreq(std::pair<int, CString> maxFrequency);

	//��ѹ������Χ
	std::pair<int, CString> GetElcPressure();
	void SetElcPressure(std::pair<int, CString> elcPressure);

	//��Ŀ���
	int GetProjectId();
	void SetProjectId(int projectId);


	//��������
	std::pair<int, CString> & GetMessureType();
	void SetMessureType(std::pair<int, CString> messureType);


	char GetAntiAliasingFiltering();
	void SetAntiAliasingFiltering(char antiAliasingFiltering);
	TbDictionary & GetIntegralType();
	void SetIntegralType(TbDictionary integralType);
	TbDictionary & GetIntegralUnits();
	void SetIntegralUnits(TbDictionary integralUnits);
	CString GetChannels();
	TbDictionary & GetChannelStatus();
	void SetChannelStatus(TbDictionary ChannelStatus);
	
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

	


	void SetSensor(TbSensor sensor);
	TbSensor & GetSensor();


};

