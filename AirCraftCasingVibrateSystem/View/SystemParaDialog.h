#pragma once
#include "afxcmn.h"
#include "CollectionParaView.h"
#include "DeviceParaView.h"
// CSystemParaDialog �Ի���

class CSystemParaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemParaDialog)

public:
	CSystemParaDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSystemParaDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_SYSTEM_PARA };
public:
	int m_CurSelTab;
	CollectionParaView   m_channelPara;
	CDeviceParaView    m_devicePara;
	CDialog* pDialog[2];  //��������Ի������ָ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSystemPara;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTcnSelchangeTabSystemPara(NMHDR *pNMHDR, LRESULT *pResult);
	void RefreshView();
};
