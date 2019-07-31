#pragma once


// CStatisticView 对话框

class CStatisticView : public CDialogEx
{
	DECLARE_DYNAMIC(CStatisticView)

public:
	CStatisticView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStatisticView();

// 对话框数据
	enum { IDD = IDD_DIALOG1_DATA_STATISTIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
