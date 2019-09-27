#pragma once
#include "afxwin.h"


// CAlarmParaSetView 对话框

class CAlarmParaSetView : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarmParaSetView)

public:
	CAlarmParaSetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAlarmParaSetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_ALARM_PARA_SET };
public:
	BOOL m_bChannelAlarm=0;
	BOOL m_bSoundAlarm=0;
	BOOL m_bAlarmLog=0;
	int m_iAlarmLimit = 1;
	CString m_strAlarm = "alarm";
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkChannelAlarm;
	CButton m_checkAlarmLog;
	CButton m_checkSoundAlarm;
	CEdit m_editAlarmLimit;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheckChannelAlarm();
	afx_msg void OnBnClickedCheckAlarmLog();
	afx_msg void OnBnClickedCheckSoundAlarm();
	afx_msg void OnBnClickedSavrAlarmSet();
};
