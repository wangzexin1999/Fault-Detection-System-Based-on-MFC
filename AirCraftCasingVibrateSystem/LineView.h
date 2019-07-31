#pragma once


// CLineView 对话框

class CLineView : public CDialogEx
{
	DECLARE_DYNAMIC(CLineView)

public:
	CLineView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLineView();

// 对话框数据
	enum { IDD = IDD_DIALOG_LINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
