#pragma once


// CDetectedDeviceManageView �Ի���

class CDetectedDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectedDeviceManageView)

public:
	CDetectedDeviceManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetectedDeviceManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECTED_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
