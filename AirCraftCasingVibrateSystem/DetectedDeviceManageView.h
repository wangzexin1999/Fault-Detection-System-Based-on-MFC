#pragma once


// CDetectedDeviceManageView 对话框

class CDetectedDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectedDeviceManageView)

public:
	CDetectedDeviceManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetectedDeviceManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECTED_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
