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
#include "AdvantechDaqController.h"
#include "TbSensor.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"
#include "redisUtil.h"
#include "RealTimeSignal.h"
#include "JsonUtil.h"
#include "DictionaryController.h"

#define WM_USER_REFRESH_CHART WM_USER + 1024

class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // �������л�����
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)
private:

	CDuChartCtrl m_chart; // ��ͼ�ؼ�
	CChartLineSerieDu *m_pLineSerie; // ��
	int m_flag = false;  // �����ؼ���С��־
	EchoSignal m_echoSignal;
	CSignalSelectView  m_signalSelectView;   //�ź�ѡ�����

	SensorController m_sensorController; ///������������

	ThreadSafeQueue<EchoSignal>  m_echoSignalQueue; // �����źŶ���
	int m_icurrentWindowNumber;  // ����
	ThreadSafeQueue<AcquiredSignal> m_collectionDataQueue;  //�ɼ�����
	int m_iSampleDataEchoTimerNum;  //�������ݻ��Դ���
	static int m_iwindowCount;//��������
	int m_realTimeSignalCaptureflag = true; // �ɼ�ʵʱ����ʱ����һ����push���������Ǹ�ֵ
	int m_icountNumsReadDraw = 0; //�������ݽ�ȡʱ������
	AdvantechDaqController m_advantechDaqController;


public:
	ThreadSafeQueue<RealTimeSignal> m_realTimeSignal;  // ʵʱ���ݶ���
	vector<AcquiredSignal> m_sampleFromFileDataQueue;  // �������д��ļ��л��
public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////���ĵ���ܶ�Ӧ���ĵ���
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// ����
public:

	/**********************************************************************
	���������� ˢ�´���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void RefershView();
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
	/**********************************************************************
	 ����������ˢ��ͼ������ 
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void RefreshGraphAttri();
	/**********************************************************************
	 ���������� �������ݻ���
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SampleDataEcho();
	/**********************************************************************
	 ���������� ���û������ݵĶ�ʱ��
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums);
	/**********************************************************************
	 ���������� ��û������ݵĶ�ʱ��
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	int SetSampleDataEchoTimerNum();
	/**********************************************************************
	 ���������� ��ʼ����
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void StartSampleEncho();
	/**********************************************************************
	 ���������� ֹͣ�����ط�
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void StopSampleEncho();
	/**********************************************************************
	 ���������� �������ݵĽ�ȡ
	 ���������dXData--x���ݣ�dYData--y���ݣ�nNums--��ȡ�ĸ���
	 ��������� 
	 �� �� ֵ�� 
	 ����˵�������ļ��ж�ȡ�������ݺ󣬷ŵ�vector���棬����ʱ��vector��ȡһ���ֻ���
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SplitVector(SmartArray<double> &dXData, SmartArray<double> &dYData,int nNums);
	/**********************************************************************
	�������������òɼ����ڵ�ͨ��
	���������
	���������
	�� �� ֵ��
	����˵�������òɼ����ڵĴ�����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSensor(TbSensor sensor);
	/**********************************************************************
	�����������õ��ɼ����ڶ�Ӧ��ͨ��
	���������
	���������
	�� �� ֵ��
	����˵�������òɼ����ڵĴ�����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetSensor(TbSensor &sensor);
	/**********************************************************************
	������������ӻ�������
	���������
	���������
	�� �� ֵ��
	����˵�������òɼ����ڵĴ�����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetEchoSignalData(EchoSignal &sensor);

	/**********************************************************************
	����������ˢ��ͼ�����Ӧ�¼�
	���������
	���������
	�� �� ֵ��
	����˵����ˢ�´���
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg LRESULT OnRefreshChart(WPARAM wParam, LPARAM lParam);


// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	DictionaryController m_dictionaryController;
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
	//afx_msg void OnButtonSignalSelect();
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
	/**********************************************************************
	��������������xy�������Сֵ�����ֵ
	���������xmin,xmax,ymin,ymax
	���������
	�� �� ֵ��
	����˵��������ֵ����Ĭ�ϲ���-1�����ʹ��Ĭ�ϲ����Ļ���Ĭ�ϵ�����Ϊ�ɼ����ڰ󶨵Ĵ������Ĳ���ȡֵ
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetChartXYCoordinateLen(double xmin = 0, double xmax = -1, double ymin = -1, double ymax = -1);
	


};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp �еĵ��԰汾
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

