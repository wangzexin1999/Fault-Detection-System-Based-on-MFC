#pragma once


// CAlarmParaSetView 对话框

class CAlarmParaSetView : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarmParaSetView)

public:
	CAlarmParaSetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAlarmParaSetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_ALARM_PARA_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
