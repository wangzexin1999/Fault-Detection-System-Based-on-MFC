#pragma once


// CStateSetDialog �Ի���

class CStateSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStateSetDialog)

public:
	CStateSetDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStateSetDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATE_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
