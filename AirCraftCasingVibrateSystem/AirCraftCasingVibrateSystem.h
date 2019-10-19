// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// AirCraftCasingVibrateSystem.h : AirCraftCasingVibrateSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#define SERSOR_NUM  4         //����������
#include "resource.h"       // ������

#include "NetConService.h"
#include "SensorService.h"
#include <vector>
#include "PDSQL.h"
#include "TbProject.h"
#include "ThreadSafeQueue.h"////�̰߳�ȫ���� 
#include "AcquiredSignal.h"
#include "SignalAcquisitionService.h"
#include "AirCraftCasingVibrateSystemView.h"
#include "redisUtil.h"
#include "httplib.h"
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// �йش����ʵ�֣������ AirCraftCasingVibrateSystem.cpp
//

class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	CNetConService  m_con;  // ����ͨ������
	bool m_bcon = false;  // �ж�����ͨ���Ƿ����ӳɹ�
	Redis *m_redisCon = new Redis();  
	bool m_bShowInfThreadActive = true;

	CString m_jsonCollectionStatusPara = "{\"collectionPlan\":\"ƽ��״̬\",\"collectionPlanTitle\" : [\"ת��\"],\"collectionPlanPara\" : [\"126hz\"]}";

	/// �û�
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*��ͼ�ؼ�ID*/
	int m_icollectSignalsStoreCount = 100000; ///�ɼ��źŵĴ洢������ 
	int m_isampleSignalsStoreCount = 100000; ///�ɼ��źŵĴ洢������ 
	int m_icollectionStatus; ////�ɼ�״̬ 0 ��ֹͣ�ɼ� 1����ʼ�ɼ� 2����ͣ�ɼ� 
	int m_signalEchoCount = 1000; //�źŻ�������
	bool m_bIsAutoSaveCollectionData = true; ///�Ƿ��Զ�����ɼ�����
	CString m_collectionRotatingSpeed = "";
	vector<SignalAcquisitionService> m_vSignalAcquisitionService; ////�źŲɼ�����
	TbRecordSignal m_recordSignal; // ��������
	double tempRead[100][1000]; ///ģ������
	httplib::Client m_cli; // http����

	std::vector<CAirCraftCasingVibrateSystemView *> m_vsignalCaptureView;///�ɼ����ڵļ���

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	PDSQL PDsql;
	PDSQL m_conPDLocalSql;
// ʵ��
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAirCraftCasingVibrateSystemApp theApp;
