#pragma once


// CSelectView 对话框

class CSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectView)

public:
	CSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
