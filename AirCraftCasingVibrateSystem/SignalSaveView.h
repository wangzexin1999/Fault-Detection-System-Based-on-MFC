#pragma once

// CSignalSaveView �Ի���

class CSignalSaveView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSaveView)

public:
	CSignalSaveView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignalSaveView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SIGNAL_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
