#pragma once

// CSignalSaveView 对话框

class CSignalSaveView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSaveView)

public:
	CSignalSaveView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalSaveView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SIGNAL_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
