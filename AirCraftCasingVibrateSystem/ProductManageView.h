#pragma once


// CProductManageView �Ի���

class CProductManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CProductManageView)

public:
	CProductManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProductManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECTED_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
