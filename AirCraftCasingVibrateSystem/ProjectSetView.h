#pragma once
#include "BaseProjectInfoView.h"
#include "ChannelParaPresetView.h"
#include "TbProject.h"
#include "CollectionPlanParaPresetView.h"
#include "afxcmn.h"

class ProjectSetView : public CDialogEx
{
	DECLARE_DYNAMIC(ProjectSetView)

public:
	ProjectSetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ProjectSetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_PROJECTSET };

protected:
	BaseProjectInfoView m_baseProjectInfoView;
	ChannelParaPresetView m_channelParaPresetView;
	int m_icurSelTabIndex;
	int m_newDialogIndex;
	TbProject m_project;
	vector<CDialog*> m_pDialogVec;  //用来保存对话框对象指针
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_projectNavigationTab;
	/**********************************************************************
	功能描述： 点击上一步的按钮
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedButtonLaststep();
	/**********************************************************************
	功能描述： 点击下一步的按钮
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedButtonNextstep();
	/**********************************************************************
	功能描述： 点击确定的按钮
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedOk();
	/**********************************************************************
	功能描述： 点击取消的按钮
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedCancel();
	/**********************************************************************
	功能描述： tab键被触发的事件，切换当前显示的窗口
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnTcnSelchangeTabProjectNavigation(NMHDR *pNMHDR, LRESULT *pResult);
};
