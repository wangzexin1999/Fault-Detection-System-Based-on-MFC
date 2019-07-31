#pragma once


// CDetectDeviceManageView 对话框

class CDetectDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectDeviceManageView)

public:
	CDetectDeviceManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetectDeviceManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECT_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
