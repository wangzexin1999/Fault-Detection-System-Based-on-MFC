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
	/**********************************************************************
	 ���������� ��ɫ�ؼ�
	 ��������� 
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	void ColorDiag();

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
};
