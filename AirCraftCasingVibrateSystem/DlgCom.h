#pragma once
#include "CDHTestHardWare.h"

// CDlgCom �Ի���

class CDlgCom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCom)

public:
	CDlgCom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgCom();

// �Ի�������
	enum { IDD = IDD_DIALOG_COM };
public:
	CDHTestHardWare m_DHHardWare;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
