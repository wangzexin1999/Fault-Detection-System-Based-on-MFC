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
	TbSensor m_tempSelectedSensor;
	/**********************************************************************
	功能描述： 初始化传感器选择的树控件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitSensorSelectTree();
	void InitSensorSelectedTree();
	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	CCherryTree m_treeSignalSelected;
	TbSensor & GetSelectedSensor();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkTreeSelectChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeSelectedChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	/**********************************************************************
	功能描述：设置采集窗口的传感器
	输入参数：
	输出参数：
	返 回 值：
	其它说明：设置采集窗口的传感器
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSensor(TbSensor sensor);
};
