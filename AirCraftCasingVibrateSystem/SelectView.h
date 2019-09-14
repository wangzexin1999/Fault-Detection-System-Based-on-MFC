#pragma once


// CSelectView 对话框

class CSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectView)

public:
	CSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectView();
public:
	BOOL bGridline;
	BOOL bCursorValue;
	BOOL bStaValue;
	BOOL bLegend;
	BOOL bMax;
	BOOL bMin;
	BOOL bAve;
	BOOL bPeak;
	BOOL bStd;
	BOOL bRms;
	int  nHSType;
	int  nVSType;
	int  nHSCount;
	int  nVSCount;
	int  nHDCount;
	int  nVDCount;
	BOOL bShowPeakList;
	int  nPeakListCount;
	int  nXieCCount;
	BOOL bShowZuiMax;
	BOOL bShowZuiMin;
	BOOL bSeparate;
	int  nSeparateColCount;
	BOOL bShowBar;
// 对话框数据
	enum { IDD = IDD_DIALOG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
