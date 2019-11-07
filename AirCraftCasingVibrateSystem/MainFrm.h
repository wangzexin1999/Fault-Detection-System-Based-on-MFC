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

// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "SystemParaView.h"
#include "ChannelParaView.h"
#include "AirCraftCasingVibrateSystemView.h"
#include <vector>
#include "GraphAttributeView.h"
#include "StateSetDockPanelView.h"
#include "SignalController.h"
#include "CollectionPlanManageView.h"
#include "ProjectSetView.h"
#include "ProjectController.h"
#include "SmartArray.h"
#include "AdvantechDaqController.h"
#include <map>
/////////////////////////////////////
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"

using namespace Automation::BDaq;
using namespace std;
/////////////////////////////////////

///ˢ��ҳ����Զ�����Ϣӳ��
#define  WM_REFRESHVIEW_BY_PROJECT (WM_USER+100)

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;
	CMFCToolBar       m_wndContrlBar;

	vector<WaveformAiCtrl *> m_vwfAiCtrl;
	CGraphAttributeView m_graphAttributeView; // ͼ�����Խ���
	SignalController m_signalController;
	ProjectController m_projectController;
	CSystemParaView    m_systemParaView;
	CChannelParaView    m_channelParaView;
	CStateSetDockPanelView m_stateSetDockPanelView;
	CDockablePane m_Panes[5];  
	vector<CString> m_vchannelIds; 
	map<CString, CAirCraftCasingVibrateSystemView*> m_mpsignalCollectionView;
	map<CString, ThreadSafeQueue<double>> m_mpcolllectioinDataQueue; ///�ɼ�������
	map<int, DOUBLE *> m_mpcolllectioinData;
	map<int, DevConfParam> m_vdevConfParams;
	ICollection<DeviceTreeNode>* m_devices;
	AdvantechDaqController m_advantechDaqController;
public:
	/**********************************************************************
	���������� ��ʼ���ɼ����ڣ������д��ڴ浽vector��
	���������nWindowInitial--���ڳ�ʼ��
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitCaptureViewVector();
	/**********************************************************************
	 ���������� ��ʼ���������ݻ���View
	 ���������nWindowInitial--���ڳ�ʼ��
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitializeSampleDataEchoView(int nWindowInitial);
	/**********************************************************************
	 ���������� ʵʱ�źŴ���
	 ���������
	 ���������
	 �� �� ֵ��
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void CMainFrame::RealTimeSignal2Server();
	/**********************************************************************
	 �����������½��ĵ�
	 ���������nwinNums--�½��ĵ�����Ŀ
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void NewDoc(int nwinNums);//

	/**********************************************************************
	���������������ɼ�����
	�������������������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void CreateCaptureWindow(vector<TbSensor> vsensor);
	/**********************************************************************
	 ���������� ��������ƽ��
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void WindowsVertical();
	/**********************************************************************
	 ���������� ���ں���ƽ��
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void WindowsHorizontal();
	/**********************************************************************
	 ���������� �ر����д���
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void CloseAllWindows();
	/**********************************************************************
	���������� �Զ���� ������Ŀˢ����ͼ���¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg LRESULT OnRefreshViewByProject(WPARAM wParam, LPARAM lParam);

	/**********************************************************************
	���������� �Զ���� ����׼���õ���Ӧ�¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void *userParam);


	/**********************************************************************
	���������� ���ɼ����Ĵ�����Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void CheckError(ErrorCode error);
	/**********************************************************************
	���������� �����߳��Զ�����ɼ����ݵ��̺߳���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void OpenThread2SaveCollectionData();

	/**********************************************************************
	���������� �Զ�����ɼ����ݵ��̺߳���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void AutoSaveCollectionData();
	/**********************************************************************
	���������� ����ɼ�����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SaveCollectionData(map<CString, ThreadSafeQueue<double>> & acquireSignal);

	/**********************************************************************
	���������� ����ɼ�����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetInstalledDevices(ICollection<DeviceTreeNode> *& devices);
	/**********************************************************************
	���������� �õ�����ͨ��
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannels(vector<CString> & channels);


	afx_msg LRESULT OnStatusInf(WPARAM wParam, LPARAM lParam); // �Զ���״̬��Ϣ�ı���Ϣ
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnOptions();
	afx_msg void OnButtonNewProject(); ///�½���Ŀ
	afx_msg void OnButtonProjectManage(); ///��Ŀ����
	afx_msg void OnButtonOpenDataFile();///�������ļ�

	afx_msg void OnButtonExportChannelPara(); ///����ͨ������
	afx_msg void OnButtonImportChannelPara(); ///����ͨ������
	afx_msg void OnButtonExportSysPara(); ///����ϵͳ����
	afx_msg void OnButtonImportSysPara(); ///����ϵͳ����
	afx_msg void OnButtonSuspendCapture();///��ͣ�ɼ�
	afx_msg void OnButtonStartCapture();///��ʼ�ɼ�
	afx_msg void OnBtnStopCapture(); ///ֹͣ�ɼ�
	afx_msg void OnBtnStartPlayback();///��ʼ�ط� 
	afx_msg void OnBtnStopPlayback(); ///ֹͣ�ط�
	afx_msg void OnBtnCloseAllWindow();///�ر����д���

	afx_msg void OnBtnStartSmaple();///��ʼ���� 
	afx_msg void OnBtnStopSample();///ֹͣ����
	afx_msg void OnBtnEngineeringUnit();///���̵�λ
	afx_msg void OnBtnAlarmSet();///��������
	afx_msg void OnButtonProduct();///��Ʒ

	afx_msg void OnBtnTransverseAmplification();
	afx_msg void OnBtnHorizontalReduction(); ///������С
	afx_msg void OnBtnVerticalReduction();///������С 
	afx_msg void OnBtnVerticalAmplification();///��������
	afx_msg void OnBtnSingleCursor();///�����
	afx_msg void OnBtnPeakValue();///��ֵ
	afx_msg void OnBtnAutoScale();///�Զ��̶� 
	afx_msg void OnBtnDefaultScale();///Ĭ�Ͽ̶�
	afx_msg void OnBtnNoCorror();///�޹��
	afx_msg LRESULT OnSetText(WPARAM wParam, LPARAM lParam);///�޸ĳ���������Ӧ�¼�

	DECLARE_MESSAGE_MAP()
	BOOL CreateCaptionBar();
public:
	// ͨ�����������ػ���ʾ
	afx_msg void OnViewChannelPara();
	afx_msg void OnUpdateViewChannelPara(CCmdUI* pCmdUI);
	// ϵͳ�������ػ���ʾ
	afx_msg void OnViewSystemPara();
	afx_msg void OnUpdateViewSystemPara(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBtnGraphAttribute();//ͼ������
	afx_msg void OnButton9();
	afx_msg void OnCheckStaSet();
	afx_msg void OnUpdateCheckStaSet(CCmdUI *pCmdUI);
	afx_msg void OnClose();

	/**********************************************************************
	���������� �򿪲ɼ��ƻ������ڵİ�ť
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����    �汾�� �޸��� �޸�����
	2019-10-07  1.0   ������  �´���
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnButtonOpenCollectionPlanManage();
	afx_msg void OnButtonOpenProjectView();
	afx_msg void OnButtonOpenProjectSetView();
};


