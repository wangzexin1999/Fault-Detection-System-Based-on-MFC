#pragma once


// CLineView 对话框

class CLineView : public CDialogEx
{
	DECLARE_DYNAMIC(CLineView)

public:
	CLineView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLineView();
public:
	int nLinePenStyle[4];
	int nLinePenWidth[4];
	int nCoorStyle;
	int nCoorWidth;
	int nGridLineStyle;
	int nGridLineWidth;
	int nCursor1Style;
	int nCursor1Width;
	int nCursor2Style;
	int nCursor2Width;
// 对话框数据
	enum { IDD = IDD_DIALOG_LINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
