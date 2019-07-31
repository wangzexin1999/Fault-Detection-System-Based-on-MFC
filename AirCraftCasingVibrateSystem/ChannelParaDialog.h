#pragma once
#include "afxcmn.h"
#include "GeneralParaView.h"
#include "TriggerParaView.h"

// CChannelParaDialog 对话框

class CChannelParaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChannelParaDialog)

public:
	CChannelParaDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChannelParaDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANNEL_PARA };
public:
	CTriggerParaView   m_triggerPara;
	CGeneralParaView   m_generalPara;
	CDialog* pDialog[2];  //用来保存对话框对象指针
	int m_CurSelTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_channelTab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
