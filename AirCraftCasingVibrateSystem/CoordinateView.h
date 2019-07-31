#pragma once


// CCoordinateView 对话框

class CCoordinateView : public CDialogEx
{
	DECLARE_DYNAMIC(CCoordinateView)

public:
	CCoordinateView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCoordinateView();

// 对话框数据
	enum { IDD = IDD_DIALOG_COORDINATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
