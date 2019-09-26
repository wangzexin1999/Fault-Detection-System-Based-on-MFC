#pragma once


// CStateSetDialog 对话框

class CStateSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStateSetDialog)

public:
	CStateSetDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStateSetDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_STATE_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
