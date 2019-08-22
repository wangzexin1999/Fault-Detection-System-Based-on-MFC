#pragma once
#include "afxcmn.h"
#include "CherryTree.h"
#include "SensorController.h"
#include <vector>
#include "TbSensor.h"
using namespace std;
class CSignalSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSelectView)

public:
	CSignalSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalSelectView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SIGNAL_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	SensorController m_sensorController;
	vector<TbSensor>  m_sensorVector;
	TbSensor m_selectedSensor;
	void InitSensorSelectTree();
	void InitSensorSelectedTree();

	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	CCherryTree m_treeSignalSelected;
	virtual BOOL OnInitDialog();
	
	afx_msg void OnNMClickTreePath(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeSelectChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeSelectedChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnTvnSelchangedTreeSelectedChannel(NMHDR *pNMHDR, LRESULT *pResult);
};
