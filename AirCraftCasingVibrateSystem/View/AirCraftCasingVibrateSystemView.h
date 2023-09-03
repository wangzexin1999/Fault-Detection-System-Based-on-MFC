
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
#include "ChannelController.h"
#include "TbChannel.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"
#include "redisUtil.h"
#include "RealTimeSignal.h"
#include "JsonUtil.h"
#include "DictionaryController.h"
#include "SignalTestRecordController.h"
#include "TbSignalTestRecord.h"
#include "DHTestHardWareController.h"
#define WM_USER_REFRESH_CHART WM_USER + 1024

class CAirCraftCasingVibrateSystemView : public CFormView
{
public:
	CAirCraftCasingVibrateSystemView();
protected: // �������л�����
	//CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)
private:
	DHTestHardWareController m_dhtestHardWareController;
	CDuChartCtrl m_chart; // ��ͼ�ؼ�
	CChartLineSerieDu *m_pLineSerie; // ��
	int m_flag = false;  // �����ؼ���С��־

	CSignalSelectView  m_signalSelectView;   //�ź�ѡ�����

	ChannelController m_channelController; ///������������

	ThreadSafeQueue<double *>  m_echoSignalQueue; // �����źŶ���

	EchoSignal m_echoSignal;

	int m_icurrentWindowNumber;  // ����

	int m_iSampleDataEchoTimerNum;  //�������ݻ��Դ���

	static int m_iwindowCount;//��������
	int m_realTimeSignalCaptureflag = true; // �ɼ�ʵʱ����ʱ����һ����push���������Ǹ�ֵ
	int m_icountNumsReadDraw = 0; //�������ݽ�ȡʱ������
	//Value m_analysisFrequency;
	SignalTestRecordController m_signalTestRecordController;
	TbSignalTestRecord m_signalTestRecord;
	double m_peak;
	double m_gross;
	TbChannel m_currentChannel;
public:
	ThreadSafeQueue<RealTimeSignal> m_realTimeSignal;  // ʵʱ���ݶ���
	vector<AcquiredSignal> m_sampleFromFileDataQueue;  // �������д��ļ��л��

	double GetPeak();
	void SetPeak(double peak);
	double GetGross();
	void SetGross(double gross);

	bool b_mutation = true;								//�Ƿ�ʹ��ͻ��
	double mutationValue = 100;								//ͻ��ֵ

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////���ĵ���ܶ�Ӧ���ĵ���
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// ����
public:

	/**********************************************************************
	���������� �����߳�ˢ�´���
	***********************************************************************/
	void openThread2RefershView();

	/**********************************************************************
	���������� �����߳�ˢ�´���
	***********************************************************************/
	void openTimer2RefershView();

	/**********************************************************************
	���������� �����߳�ˢ�´���
	***********************************************************************/
	void killTimer2RefershView();

	/**********************************************************************
	���������� ˢ�´��ڵ��̺߳���
	***********************************************************************/
	void RefershView();
	
	/**********************************************************************
	���������� �õ�view�е�ChartCtrl�ؼ�
	***********************************************************************/
	CDuChartCtrl & GetChartCtrl();



	/**********************************************************************
	���������� ���õ�ǰ���ڵ����
	***********************************************************************/
	void SetViewNumber(int windowNumber);



	/**********************************************************************
	���������� ���ô���
	***********************************************************************/
	void ResetView();




	/**********************************************************************
	 ����������ˢ��ͼ������ 
	***********************************************************************/
	void RefreshGraphAttri();




	/**********************************************************************
	 ���������� �������ݻ���
	***********************************************************************/
	void SampleDataEcho();





	/**********************************************************************
	 ���������� ���û������ݵĶ�ʱ��
	***********************************************************************/
	void SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums);





	/**********************************************************************
	 ���������� ��û������ݵĶ�ʱ��
	***********************************************************************/
	int GetSampleDataEchoTimerNum();
	/**********************************************************************
	 ���������� ��ʼ����
	***********************************************************************/
	void StartSampleEncho();
	/**********************************************************************
	 ���������� ֹͣ�����ط�
	***********************************************************************/
	void StopSampleEncho();
	/**********************************************************************
	 ���������� �������ݵĽ�ȡ
	 ���������dXData--x���ݣ�dYData--y���ݣ�nNums--��ȡ�ĸ���
	 ����˵�������ļ��ж�ȡ�������ݺ󣬷ŵ�vector���棬����ʱ��vector��ȡһ���ֻ���
	***********************************************************************/
	void SplitVector(SmartArray<double> &dXData, SmartArray<double> &dYData,int nNums);
	/**********************************************************************
	�������������òɼ����ڵ�ͨ��
	����˵�������òɼ����ڵĴ�����
	***********************************************************************/
	void SetChannel(TbChannel channel);
	/**********************************************************************
	�����������õ��ɼ����ڶ�Ӧ��ͨ��
	����˵�������òɼ����ڵĴ�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannel(TbChannel &channel);
	/**********************************************************************
	������������ӻ�������
	����˵�������òɼ����ڵĴ�����
	***********************************************************************/
	void PushEchoSignal(double* chartPoints);
	/**********************************************************************
	������������ӻ�������
	����˵�������òɼ����ڵĴ�����
	***********************************************************************/
	void clearEchoSignal();

	/**********************************************************************
	������������ӻ�������
	����˵�������òɼ����ڵĴ�����
	***********************************************************************/
	void SetEchoSignal(double* chartPoints);

	int echoStartTime = 0;
	/**********************************************************************
	����������ˢ��ͼ�����Ӧ�¼�
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

	int a = 1;

	/**********************************************************************
	��������������xy�������Сֵ�����ֵ
	���������xmin,xmax,ymin,ymax
	����˵��������ֵ����Ĭ�ϲ���-1�����ʹ��Ĭ�ϲ����Ļ���Ĭ�ϵ�����Ϊ�ɼ����ڰ󶨵Ĵ������Ĳ���ȡֵ
	***********************************************************************/
	void SetChartXYCoordinateLen(double xmin = -1, double xmax = -1, double ymin = -1, double ymax = -1);
	


};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp �еĵ��԰汾
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

