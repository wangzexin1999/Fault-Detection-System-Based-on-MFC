#pragma once
#include "afxwin.h"


// CSelectView �Ի���

class CSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectView)

public:
	CSelectView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectView();
public:
	BOOL m_bGridline = TRUE; // ������
	BOOL m_bStaValue = TRUE;  //ͳ����Ϣ
	BOOL m_bMax = TRUE;   // ���
	BOOL m_bMin = TRUE;   // ��С
	BOOL m_bAve = TRUE;    // ƽ��
	BOOL m_bPeak = TRUE;    // ���ֵ
	BOOL m_bEffectiveValue = TRUE;   // ��Чֵ
	BOOL m_bPeakValue = TRUE;
	
	CString m_select = "select";
// �Ի�������
	enum { IDD = IDD_DIALOG_SELECT };
public:
	/**********************************************************************
	 ���������� ͳ����Ϣ����ؼ��Ƿ��û�
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void StatisticInfCtrlIsEnable(bool bEnable);
	/**********************************************************************
	 ���������� ��ʼ���ؼ��ͳ�ʼ������
	 ���������bAttri--���ԣ� btnCtrl--�ؼ�
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitCtrlAndAttri(CString strFromINI, BOOL &bAttri, CButton &btnCtrl);
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
	/**********************************************************************
	 ���������� ��ʼ����Ա���ԣ�������check
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri2();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton m_checkGridLine;
	CButton m_checkStatisticInf;
	CButton m_ckeckMaxValue;
	CButton m_checkMinValue;
	CButton m_checkEffectiveValue;
	CButton m_checkMeanValue;
	afx_msg void OnBnClickedCheckGridLine();
	CButton m_checkPeakValue;
	afx_msg void OnBnClickedCheckStatisticInf();
	afx_msg void OnBnClickedCheckMaxValue();
	afx_msg void OnBnClickedCheckMinValue();
	afx_msg void OnBnClickedCheckEffectiveValue();
	afx_msg void OnBnClickedCheckMeanValue();
	afx_msg void OnBnClickedCheckPeakValue();





};
