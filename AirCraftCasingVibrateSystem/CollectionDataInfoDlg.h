#pragma once
#include "AirCraftCasingVibrateSystem.h"
#include "afxwin.h"

// CollectionDataInfoDlg 对话框

class CollectionDataInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionDataInfoDlg)

public:
	CollectionDataInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionDataInfoDlg();

// 对话框数据
	enum { IDD = IDD_COLLECTIONDATAINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_collectionRotatingSpeedEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
