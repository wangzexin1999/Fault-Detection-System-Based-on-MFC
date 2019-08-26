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
#include "SensorController.h"
#include "GraphAttributeView.h"
#include "TbSensor.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"

class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // �������л�����
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)
	
private:
	CDuChartCtrl m_chart;
	CChartLineSerieDu *m_pLineSerie;
	int m_flag = false;  // �����ؼ���С��־
	CSignalSelectView  m_signalSelectView;   //�ź�ѡ�����
	CGraphAttributeView m_graphAttributeView; // ͼ�����Խ���
	SensorController m_sensorController; ///������������
	ThreadSafeQueue<EchoSignal>  m_echoSignalQueue;

	int m_icurrentWindowNumber;
	ThreadSafeQueue<AcquiredSignal> m_collectionDataQueue;

	static int m_iwindowCount;//��������

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////���ĵ���ܶ�Ӧ���ĵ���
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// ����
public:

	 double m_readFromCSVFile[100][1000];//�ļ��Ĳ����������飬������

	 /**********************************************************************
	 ���������� �ɼ�&��������
	 ���������
	 ���������
	 �� �� ֵ��
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	 void  CaptureData();
	/**********************************************************************
	���������� �����̲߳ɼ�����
	���������  
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void OpenThread2CaptureData();
	/**********************************************************************
	���������� ˢ��ͼ��ؼ�
	��������� 
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void RefershChartCtrlData();

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
	void SaveCollectionData(ThreadSafeQueue<AcquiredSignal> acquireSignalQueue);
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
	���������� �Զ�����������ݵ��̺߳���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void AutoSaveSampleData();

	/**********************************************************************
	���������� �õ�view�е�ChartCtrl�ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	CDuChartCtrl & GetChartCtrl();

	/**********************************************************************
	���������� ���õ�ǰ���ڵ����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetViewNumber(int windowNumber);

	/**********************************************************************
	���������� ���ô���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void ResetView();

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
	afx_msg void OnBtnGraphAttr();
	
	void OnBtnTransverseAmplification();
	void OnBtnHorizontalReduction();
	void OnBtnVerticalReduction();
	void OnBtnVerticalAmplification();
	void OnBtnSingleCursor();
	void OnBtnPeakValue();
	void OnBtnAutoScale();
	void OnBtnSelfScale();
	void OnBtnNoCorror();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp �еĵ��԰汾
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

