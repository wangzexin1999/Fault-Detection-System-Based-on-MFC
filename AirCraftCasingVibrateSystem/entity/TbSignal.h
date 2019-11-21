#pragma once
#include "TbProduct.h"
#include "TbSensor.h"
#include "TbTestingDevice.h"
#include <vector>
#include "TbProject.h"
using namespace std;

class TbSignal
{
public:
	TbSignal(int signalId = 0);
	~TbSignal();

private:

	int m_signalId;
	CString m_saveTime;
	CString m_signalType;
	int m_productId;
	char m_signalStatus;
	CString m_dataUrl;
	int  m_projectId;
	int m_testingDeviceId;
	CString m_collectionStatus;
	int m_pointCount;
	CString m_collectionPara;

	/*ͨ������*/
	int m_iChannelNums = 0;
	/*�豸��*/
	int m_iDeviceID = 0;
	/*��ʼͨ��*/
	int m_iStartChannel = 0;
	/*����ͨ��*/
	int m_iEndChannel = 0;
	/*�ɼ�Ƶ��*/
	int m_iCollectFre = 0;
	/*�ɼ��ƻ�����*/
	char  m_cCollectPlanPara[64];
	/*�źŴ�С*/
	long long m_llSiganlSize = 0;

public:
	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetSaveTime();
	void SetSaveTime(CString saveTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	int   GetProductId();
	void SetProductId(int productId);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);
	void SetProjectId(int projectId);
	int   GetProjectId();
	int  GetTestingDeviceId();
	void SetTestingDeviceId(int  testingDeviceId);
	void SetCollectionStatus(CString para);
	CString GetCollectionStatus();
	void SetPointCount(int pointNumber);
	int GetPointCount();
	CString GetCollectionPara();
	void SetCollectionPara(CString collectionpara);
};

