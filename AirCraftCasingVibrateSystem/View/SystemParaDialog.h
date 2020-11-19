#pragma once
#include "afxcmn.h"
#include "CollectionParaView.h"
#include "DeviceParaView.h"
// CSystemParaDialog 对话框

class CSystemParaDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemParaDialog)

public:
	CSystemParaDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSystemParaDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_SYSTEM_PARA };
public:
	int m_CurSelTab;
	CollectionParaView   m_channelPara;
	CDeviceParaView    m_devicePara;
	CDialog* pDialog[2];  //用来保存对话框对象指针
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSystemPara;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTcnSelchangeTabSystemPara(NMHDR *pNMHDR, LRESULT *pResult);
	void RefreshView();
};
