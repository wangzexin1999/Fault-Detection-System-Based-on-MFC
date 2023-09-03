/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ͨ�ò�������.��Ҫʵ��ͨ�ò�����ʾ��ͨ�ò������á���Ӧ��ʵ�����ļ�ΪGeneralParaView.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-05-24
�������:
History:
1. Date:    2018-05-24         Author:����
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "afxcmn.h"
#include "GridCtrl_src/GridCtrl.h"
#include "ChannelParaController.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
#include "CDHTestHardWare.h"
#include "TbProject.h"
#include "TestController.h"
#include "SensorController.h"

using namespace  std;


// CGeneralParaView �Ի���
// CMyDialog �Ի���
//const int theApp.SHOW_CHANNEL_FULLVALUE_ = 5; 	/// ��������1
//const int theApp.SHOW_CHANNEL_SENSECOEF_ = 6; 	/// ������������1
//const int SHOW_CHANNEL_UPFREQ_ = 10; 	/// ����Ƶ��1
//const int SHOW_CHANNEL_ACQ_INPUTMODE_ = 12; 	/// ���뷽ʽ1
class CGeneralParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneralParaView)

public:
	CGeneralParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGeneralParaView();
	void GetParamSelectValue(string strMachineIP);
	CString m_strSenseCoef;
	int BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator);
	// �Ի�������
	enum { IDD = IDD_DIALOG_GENERAL_PARA };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_generalParaGridCtrl;

	DictionaryController m_dictionController;
	vector<TbDictionary> m_vwindowTypes;  // ������
	vector<TbDictionary> m_vinputMethods; // ���뷽ʽ
	list<string> m_listFullValue;
	list<string> m_listUpFreq;
	list<string> m_elcpressure;
	list<string> m_listInputMode;
	DECLARE_MESSAGE_MAP()
	ChannelParaController m_channelParaController;
	TestController m_testController;
	SensorController m_sensorController;
	std::vector<TbTestlocation> m_testLocationVec;
	std::vector<TbSensor> m_sensorVec;

public:
	virtual BOOL OnInitDialog();
	/**********************************************************************
	����������ͨ����������˫���¼���˫�����ÿ��޸���Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridEndEdit(NMHDR *pNotifyStruct, LRESULT* pResult);
	void GridCtrlInit();
	void GeneralComboInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

};
