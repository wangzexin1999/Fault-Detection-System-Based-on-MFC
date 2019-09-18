/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� CFontView.h
����ժҪ�� �������õ��������ã���Ӧ��ʵ�����ļ�ΪCFontView.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-09-17
�������:
History:
1. Date:    2018-09-17         Author:����
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "afxwin.h"


// �������������
struct  FontAttri
{
	LOGFONT m_lFont; // ��������
	int m_lFontSize;  // �����С
};


// CFontView �Ի���

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)
public:
	FontAttri m_lFontXCoor; //x��
	FontAttri m_lFontYCoor; // y��
	FontAttri m_lFontXUnit; // x��λ
	FontAttri m_lFontYUnit; //y��λ
	FontAttri m_lFontCursorValue; // ���
	FontAttri m_lFontStaValue;  // ͳ����Ϣ
	FontAttri m_lFontLegend;   // ͼ��

	CString m_font = "font";
public:
	CFontView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFontView();

// �Ի�������
	enum { IDD = IDD_DIALOG_FONT };

public:
	/**********************************************************************
	 ���������� ��ʼ������ؼ���Ĭ��ѡ��
	 ���������
	 ��������� 
	 �� �� ֵ�� LOGFONT ---����Ĭ������
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	LOGFONT InitFontDialog();
	/**********************************************************************
	 ������������ʼ������ 
	 ��������� fonAttri --���壻strInput--�������ļ��������ַ���
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitFont(FontAttri &fonAttri,CString strInput);
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
	CButton m_xCoor;
	CButton m_yCoor;
	CButton m_cursorValue;
	CButton m_xUnit;
	CButton m_yUnit;
	CButton m_cursorMark;
	CButton m_statisticInf;
	CButton m_textNote;
	CButton m_projectInf;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonXcoor();
	afx_msg void OnBnClickedButtonYcoor();
	afx_msg void OnBnClickedButtonCursorValue();
	afx_msg void OnBnClickedButtonXUnit();
	afx_msg void OnBnClickedButtonYUnit();
	afx_msg void OnBnClickedButtonCursorMark();
	afx_msg void OnBnClickedButtonStatistisInf();
	afx_msg void OnBnClickedButtonTextInf();
	afx_msg void OnBnClickedButtonProjectInf();
};
