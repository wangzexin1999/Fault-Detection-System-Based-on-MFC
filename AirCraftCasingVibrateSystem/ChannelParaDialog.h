#pragma once
#include "afxcmn.h"
#include "GeneralParaView.h"
#include "TriggerParaView.h"

// CChannelParaDialog �Ի���

class CChannelParaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChannelParaDialog)

public:
	CChannelParaDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChannelParaDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANNEL_PARA };
public:
	CTriggerParaView   m_triggerPara;
	CGeneralParaView   m_generalPara;
	CDialog* pDialog[2];  //��������Ի������ָ��
	int m_CurSelTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_channelTab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
