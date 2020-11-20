

// MainFrm.h : CMainFrame ��Ľӿ�
#pragma once
#include "SystemParaView.h"
#include "ChannelParaView.h"
#include "AirCraftCasingVibrateSystemView.h"
#include <vector>
#include "GraphAttributeView.h"
#include "StateSetDockPanelView.h"
#include "SumsignalController.h"
#include "CollectionPlanManageView.h"
#include "ProjectSetView.h"
#include "ProjectController.h"
#include "SmartArray.h"
#include "SignalController.h"
#include "AdvantechDaqController.h"
#include <map>
#include "JsonUtil.h"
#include "TbRecordSignal.h"
#include "UUIDUtil.h"
#include "TbSumsignal.h"
#include "ChannelController.h"

#include "TbSumsignalLabel.h"
#include"SumsignalLabelController.h"
#include "AlarmparaController.h"
#include "TbAlarmpara.h"
/////////////////////////////////////
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"
#include "DlgCom.h"
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

private:
	class CDHTestHardWare *m_pHardWare;
	class CDlgCom * m_pComDialog;

protected:  // �ؼ���Ƕ���Ա

	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;
	CMFCToolBar       m_wndContrlBar;
	vector<WaveformAiCtrl *> m_vwfAiCtrl;
	CGraphAttributeView m_graphAttributeView; // ͼ�����Խ���
	SumsignalController m_sumsignalController;
	SignalController m_signalController;
	ProjectController m_projectController;
	CSystemParaView    m_systemParaView;
	CChannelParaView    m_channelParaView;
	CStateSetDockPanelView m_stateSetDockPanelView;
	CDockablePane m_Panes[5];
	vector<CString> m_vchannelCodes;
	map<CString, CAirCraftCasingVibrateSystemView*> m_mpsignalCollectionView;
	map<CString, ThreadSafeQueue<double>> m_mpcolllectioinDataQueue; ///�ɼ�������
	map<int, DOUBLE *> m_mpcolllectioinData;
	map<int, DevConfParam> m_vdevConfParams;
	ICollection<DeviceTreeNode>* m_devices;
	AdvantechDaqController m_advantechDaqController;
	//Value m_sampleFrequency;
	double m_sampleFrequency;
	//Value m_analysisFrequency;
	double m_analysisFrequency;
	int m_icollectionPoints;
	JsonUtil m_jsonUtil;
	Value m_channelInfo;
	Value m_collectionStatus;
	Document m_doc;
	TbRecordSignal m_recordSignal; // ��������
	TbSumsignalLabel m_sumsignalLabel;
	SumsignalLabelController m_sumsignalLabelController;
	ofstream m_outputStream;
	ifstream m_inputStream;
	vector<ofstream>v_outputStream;
	TbRecordSignal m_selectedRecordSignal;
	bool m_bIsAnalyseFreMin = false;
	bool m_bIsAnalyseFreMax = false;
	int m_iAnalyseFreMax;
	int m_iAnalyseFreMin;
	ChannelController m_ChannelController;

	SignalTestRecordController m_SignalTestRecordController;
	vector<TbSignalTestRecord> m_vSignalTestRecord;
	AlarmparaController m_AlarmparaController;
	vector<TbAlarmpara> m_vAlarmpara;
	/**********************************************************************
	���������� ����ͨ����Ϣ��jsonֵ
	***********************************************************************/
	void SetChannelInfoJsonValue();



	/**********************************************************************
	���������� ���òɼ�״̬��Ϣ��jsonֵ
	***********************************************************************/


	void SetCollectionStatusJsonValue();
public:


	int m_isampleFrequency; ///����Ƶ��

	/**********************************************************************
	���������� ��ʼ���ɼ����ڣ������д��ڴ浽vector��
	���������nWindowInitial--���ڳ�ʼ��
	***********************************************************************/
	void InitCaptureViewVector();


	/**********************************************************************
	���������� ��ʼ���������ݻ���View
	���������nWindowInitial--���ڳ�ʼ��
	***********************************************************************/
	void InitializeSampleDataEchoView(int nWindowInitial);



	/**********************************************************************
	���������� ʵʱ�źŴ���
	***********************************************************************/
	void CMainFrame::RealTimeSignal2Server();



	/**********************************************************************
	�����������½��ĵ�
	***********************************************************************/
	void NewDoc(int nwinNums);//



	/**********************************************************************
	���������������ɼ�����
	�������������������
	***********************************************************************/
	void CreateCaptureWindow(vector<TbChannel> vchannel);



	/**********************************************************************
	���������� ��������ƽ��
	***********************************************************************/
	void WindowsVertical();



	/**********************************************************************
	���������� ���ں���ƽ��
	***********************************************************************/
	void WindowsHorizontal();



	/**********************************************************************
	���������� �ر����д���
	***********************************************************************/
	void CloseAllWindows();




	/**********************************************************************
	���������� �Զ���� ������Ŀˢ����ͼ���¼�
	***********************************************************************/
	afx_msg LRESULT OnRefreshViewByProject(WPARAM wParam, LPARAM lParam);



	/**********************************************************************
	���������� �Զ���� ����׼���õ���Ӧ�¼�
	***********************************************************************/
	static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void *userParam);



	/**********************************************************************
	���������� ���ɼ����Ĵ�����Ϣ
	***********************************************************************/
	void CheckError(ErrorCode error);



	/**********************************************************************
	���������� �����߳��Զ�����ɼ����ݵ��̺߳���
	***********************************************************************/
	void OpenThread2SaveCollectionData();




	/**********************************************************************
	���������� �����̴߳ӱ��ض�ȡ����
	***********************************************************************/
	void GetDataFromlocal();
	void Pre_GetDataFromlocal();




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
	//afx_msg void OnBtnCloseAllWindow();///�ر����д���
	afx_msg void OnSlider1();
	afx_msg void OnUpdateSlider1(CCmdUI *pCmdUI);
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
	//afx_msg void OnButton9();
	afx_msg void OnCheckStaSet();
	afx_msg void OnUpdateCheckStaSet(CCmdUI *pCmdUI);
	afx_msg void OnClose();

	/**********************************************************************
	���������� �򿪲ɼ��ƻ������ڵİ�ť
	***********************************************************************/
	afx_msg void OnButtonOpenCollectionPlanManage();
	afx_msg void OnButtonOpenProjectView();
	afx_msg void OnButtonOpenProjectSetView();
	afx_msg void OnUpdateEditAnalyseFreMin(CCmdUI *pCmdUI);
	afx_msg void OnEditAnalyseFreMin();
	afx_msg void OnEditAnalyseFreMax();
	afx_msg void OnUpdateEditAnalyseFreMax(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrRibbonI(CCmdUI *pCmdUI);
};


