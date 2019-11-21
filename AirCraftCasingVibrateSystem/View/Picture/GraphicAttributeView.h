#pragma once


// CGraphicAttributeView 对话框

class CGraphicAttributeView : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphicAttributeView)

public:
	CGraphicAttributeView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGraphicAttributeView();

// 对话框数据
	enum { IDD = IDD_DIALOG_GRAPHIC_ATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
