#pragma once


// CFontView �Ի���

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)

public:
	CFontView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFontView();

// �Ի�������
	enum { IDD = IDD_DIALOG_FONT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
