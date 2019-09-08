#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"

// BaseProjectInfoView 对话框

class BaseProjectInfoView : public CDialogEx
{
	DECLARE_DYNAMIC(BaseProjectInfoView)

public:
	BaseProjectInfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BaseProjectInfoView();

// 对话框数据
	enum { IDD = IDD_PROJECTBASEINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	CGridCtrl m_projectPlanGridCtrl;
	
	void GridCtrlInit();

	/**********************************************************************
	功能描述：检测设备表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	void SetGridCellCheck(int row,int col,bool isChecked);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
