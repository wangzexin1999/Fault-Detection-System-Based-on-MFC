#pragma once


// CFontView 对话框

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)
public:
	LOGFONT lFontXCoor;
	LOGFONT lFontYCoor;
	LOGFONT lFontXUnit;
	LOGFONT lFontYUnit;
	LOGFONT lFontCursorValue;
	LOGFONT lFontStaValue;
	LOGFONT lFontLegend;
public:
	CFontView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFontView();

// 对话框数据
	enum { IDD = IDD_DIALOG_FONT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
