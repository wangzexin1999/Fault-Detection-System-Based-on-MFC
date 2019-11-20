#pragma once
#include "afxbutton.h"


// CColorView �Ի���

class CColorView : public CDialogEx
{
	DECLARE_DYNAMIC(CColorView)

public:
	CColorView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CColorView();

// �Ի�������
	enum { IDD = IDD_DIALOG_CORLOR };
public:
	COLORREF m_colSerie[4];					 // ������ɫ
	COLORREF m_colBKColor;                    // ������ɫ
	COLORREF m_colGBKColor;                   // ͼ����������ɫ
	COLORREF m_colTBKColor;                   // ��Ϣ��������ɫ
	COLORREF m_colGridLineColor;              // ��������ɫ
	COLORREF m_colCoorColor;                  // ��������ɫ
	COLORREF m_colCursor1;                    // ���1��ɫ
	COLORREF m_colCursor2;                    // ���2��ɫ
	COLORREF m_colScale;						// �̶���ɫ
	COLORREF m_colXCoor;						// X������ɫ
	COLORREF m_colYCoor;						// Y������ɫ
	COLORREF m_colStatisticInf;               // ͳ����Ϣ��ɫ
	CString m_color = "color";
public:
	/**********************************************************************
	 ���������� ��ɫ�ؼ�
	 ��������� 
	 ��������� 
	 �� �� ֵ�� ��ɫ
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	COLORREF  GetColorDiag();
	/**********************************************************************
	 ���������� ���ð�ť����
	 ���������btn--��ť��color--��ɫ
	 ��������� 
	 �� �� ֵ��void 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetMFCButtonColor(CMFCButton & btn, COLORREF color);
	/**********************************************************************
	 ���������� ��ʼ����Ա����
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_windowBGColor;
	CMFCButton m_graphBGColor;
	CMFCButton m_infWinBGColor;
	CMFCButton m_series1Color;
	CMFCButton m_series2Color;
	CMFCButton m_series3Color;
	CMFCButton m_series4Color;
	CMFCButton m_gridColor;
	CMFCButton m_coordinateColor;
	CMFCButton m_scaleColor;
	CMFCButton m_cursorColor;
	CMFCButton m_xAxisColor;
	CMFCButton m_yAxisColor;
	CMFCButton m_statisticsInfColor;
	afx_msg void OnBnClickedMfcbuttonWinBg();
	afx_msg void OnBnClickedMfcbuttonGraphBg();
	afx_msg void OnBnClickedMfcbuttonInfBg();
	afx_msg void OnBnClickedMfcbuttonSeris1Bg();
	afx_msg void OnBnClickedMfcbuttonSeris2Bg();
	afx_msg void OnBnClickedMfcbuttonSeris33Bg();
	afx_msg void OnBnClickedMfcbuttonSeris4Bg();
	afx_msg void OnBnClickedMfcbuttonGridBg();
	afx_msg void OnBnClickedMfcbuttonCoorBg();
	afx_msg void OnBnClickedMfcbuttonScaleBg();
	afx_msg void OnBnClickedMfcbuttonCurlorBg();
	afx_msg void OnBnClickedMfcbuttonXBg();
	afx_msg void OnBnClickedMfcbuttonYBg();
	afx_msg void OnBnClickedMfcbuttonStatiscBg();
	virtual BOOL OnInitDialog();
};
