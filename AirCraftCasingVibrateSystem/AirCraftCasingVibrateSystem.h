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
#include <queue>
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// �йش����ʵ�֣������ AirCraftCasingVibrateSystem.cpp
//
class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	unsigned int m_count;
	unsigned int m_count2;
	const size_t m_c_arrayLength = 2096;

	double m_readX[102400];//��ȡ
	double m_readY[102400];

	double m_readDrawX[2096];//��ȡ��
	double m_readDrawY[2096];

	double m_dSaveX[102400];// �洢
	double m_dSaveY[102400];

	CNetConService  m_con;  // ����ͨ������
	bool m_bcon = false;  // �ж�����ͨ���Ƿ����ӳɹ�

	int countNums = 0;
	int countNumsReadDraw = 0;
	// ���������
	vector<CSensorService>  m_vSersor;
	bool m_bThreadActive = true; // �ɼ������߳̿��Ʊ�׼
	bool m_bShowInfThreadActive = true;
	/// �û�
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*��ͼ�ؼ�ID*/

	vector<queue<CSignal>> m_sampleData;
	 
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	PDSQL PDsql;
// ʵ��
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAirCraftCasingVibrateSystemApp theApp;
