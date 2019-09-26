#pragma once
#include "afxcmn.h"
#include "GeneralParaView.h"
#include "TriggerParaView.h"
#include "GeometricParaView.h"
// CChannelParaDialog �Ի���

class CChannelParaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChannelParaDialog)

public:
	CChannelParaDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChannelParaDialog();
	void RefreshDlg();
// �Ի�������
	enum { IDD = IDD_DIALOG_CHANNEL_PARA };
private:

	CTriggerParaView   m_triggerParaView;
	CGeneralParaView   m_generalParaView;
	CGeometricParaView m_geometricParaView;

	CDialog* pDialog[5];  //��������Ի������ָ��
	int m_CurSelTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_channelTab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
