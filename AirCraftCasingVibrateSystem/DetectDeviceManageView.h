#pragma once


// CDetectDeviceManageView �Ի���

class CDetectDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectDeviceManageView)

public:
	CDetectDeviceManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetectDeviceManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECT_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
