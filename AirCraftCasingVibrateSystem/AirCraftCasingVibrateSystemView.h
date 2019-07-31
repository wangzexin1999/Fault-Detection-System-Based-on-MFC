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

// AirCraftCasingVibrateSystemView.h : CAirCraftCasingVibrateSystemView ��Ľӿ�
//

#pragma once
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartAxis.h"
#include "ChartCtrl/ChartAxisLabel.h"
#include "ChartCtrl/ChartDragLineCursorDu.h"
#include "ChartCtrl/DuChartCtrl.h"
#include "ChartCtrl/ChartStandardAxisDu.h"
#include "ChartCtrl/DuChartCtrlStaticFunction.h"
#include "ChartCtrl/ChartLineSerieDu.h"
#include "resource.h"
#include "SignalSelectView.h"
#include "CheckTaskController.h"
#include "GraphAttributeView.h"
#include "AlarmParaSetView.h"
#include "NewProjectView.h"
#include "EngineerUnitView.h"
#include "ProjectManageView.h"
#include "SignalDataView.h"
#include "DetectDeviceManageView.h"
#include "DetectedDeviceManageView.h"
#include "FileUtil.h"
class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // �������л�����
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

// ����
public:
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// ����
public:
	CDuChartCtrl m_chart;
	CChartLineSerieDu *m_pLineSerie;
	int m_flag = false;  // �����ؼ���С��־
	int m_nChannelNums = 0; // ͨ������
	CAirCraftCasingVibrateSystemView * m_dview[20]; //��ͼ
	CCheckTaskController  m_signalMainController;// �źŵ�ҵ���߼�
	CSignalSelectView  m_signalSelectView;   //�ź�ѡ�����
	CGraphAttributeView m_graphAttributeView; // ͼ�����Խ���
	CNewProjectView m_newProjectView;    // ��Ŀ�������
	CFileUtil  m_fileUtile;
	/**********************************************************************
	���������� ��ȡ������ʾ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void drawMoving2();
	/**********************************************************************
	���������� �������ƶ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void LeftMoveArray(double* ptr, size_t length, double data);

	/**********************************************************************
	���������� �����ж��ٸ�ͨ��
	���������nChannelNums -- ͨ������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool CalculateChannelNum(int &nChannelNums);
	/**********************************************************************
	���������� ��ʼ�ɼ���ͼ
	���������nViewIndex--�����ٸ�
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool DrawLining(int nViewIndex);
	/**********************************************************************
	���������� ת����JSON��ʽ
	���������nXvalue -- Xֵ�� nYValue--Yֵ
	���������strData -- �����JSON�ַ���
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool  ConvertJSON(double dXvalue[], double dYValue[], CString &strData);
	/**********************************************************************
	���������� ������ɫ,
	���������nR--red,nG--green,nB--blue
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	COLORREF SetColor(int nR, int nG, int nB);
	/**********************************************************************
	���������� ��ʼ������ƴ������,
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool SplitData();
	/**********************************************************************
	���������� // �õ���������,
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetPartArray();
	/**********************************************************************
	������������ʾ��Ϣ,
	���������nType 1--�ɼ���ʾ 2--�ط���ʾ
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool DisplayInf(int nType);
	/**********************************************************************
	������������ʼ��view
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool InitializeView();
	/**********************************************************************
	������������ʾ����
	���������nChannelNum--ͨ������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool ShowDataToView(int nChannelNum);
	/**********************************************************************
	 ���������� ��ʼ�ɼ�ͨ������
	 ��������� 
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	void StartSampleChannelDatat();
// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CAirCraftCasingVibrateSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnButtonSignalSelect();
	afx_msg void OnButtonNewProject();
	afx_msg void OnButton2SaveProject();
	afx_msg void OnButtonProjectManage();
	afx_msg void OnButtonOpenDataFile();
	afx_msg void OnButtonExportChannelPara();
	afx_msg void OnButtonImportChannelPara();
	afx_msg void OnButtonExportSysPara();
	afx_msg void OnButtonImportSysPara();
	afx_msg void OnButtonSuspendCapture();
	afx_msg void OnButtonStartCapture();
	afx_msg void OnBtnStopCapture();
	afx_msg void OnBtnStopPlayback();
	afx_msg void OnBtnStartPlayback();
	afx_msg void OnBtnCloseAllWindow();
	afx_msg void OnBtnTransverseAmplification();
	afx_msg void OnBtnHorizontalReduction();
	afx_msg void OnBtnVerticalReduction();
	afx_msg void OnBtnVerticalAmplification();
	afx_msg void OnBtnSingleCursor();
	afx_msg void OnBtnPeakValue();
	afx_msg void OnBtnAutoScale();
	afx_msg void OnBtnSelfScale();
	afx_msg void OnBtnNoCorror();
	afx_msg void OnBtnStartSmaple();
	afx_msg void OnBtnStopSample();
	afx_msg void OnBtnProjectUnit();
	afx_msg void OnBtnAlarmSet();
	afx_msg void OnBtnGraphAttr();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnButtonDetectDevice();
	afx_msg void OnButtonDetectedDevice();
};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp �еĵ��԰汾
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

