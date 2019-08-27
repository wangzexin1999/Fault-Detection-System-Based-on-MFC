#pragma once
#include "AirCraftCasingVibrateSystem.h"
#include "afxwin.h"

// CollectionDataInfoDlg �Ի���

class CollectionDataInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionDataInfoDlg)

public:
	CollectionDataInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionDataInfoDlg();

// �Ի�������
	enum { IDD = IDD_COLLECTIONDATAINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_collectionRotatingSpeedEdit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
