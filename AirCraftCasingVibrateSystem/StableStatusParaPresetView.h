#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
// StableStatusParaPresetView 对话框

class StableStatusParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(StableStatusParaPresetView)

public:
	StableStatusParaPresetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StableStatusParaPresetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_STABLESTATUSPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_stableStatusGridCtrl;
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()

	/**********************************************************************
	功能描述：转速等参数表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	/**********************************************************************
	功能描述：设置表格中的多选框的选中状态
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetGridCellCheck(int row, int col, bool isChecked);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
};
