#pragma once


// CLineView �Ի���

class CLineView : public CDialogEx
{
	DECLARE_DYNAMIC(CLineView)

public:
	CLineView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLineView();

// �Ի�������
	enum { IDD = IDD_DIALOG_LINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
