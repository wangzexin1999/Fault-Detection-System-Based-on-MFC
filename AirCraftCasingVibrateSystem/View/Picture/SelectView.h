#pragma once
#include "afxwin.h"


// CSelectView 对话框

class CSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectView)

public:
	CSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectView();
public:
	BOOL m_bGridline = TRUE; // 网络线
	BOOL m_bStaValue = TRUE;  //统计信息
	BOOL m_bMax = TRUE;   // 最大
	BOOL m_bMin = TRUE;   // 最小
	BOOL m_bAve = TRUE;    // 平均
	BOOL m_bPeak = TRUE;    // 峰峰值
	BOOL m_bEffectiveValue = TRUE;   // 有效值
	BOOL m_bPeakValue = TRUE;
	
	CString m_select = "select";
// 对话框数据
	enum { IDD = IDD_DIALOG_SELECT };
public:
	/**********************************************************************
	 功能描述： 统计信息子项控件是否置灰
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void StatisticInfCtrlIsEnable(bool bEnable);
	/**********************************************************************
	 功能描述： 初始化控件和初始化属性
	 输入参数：bAttri--属性； btnCtrl--控件
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitCtrlAndAttri(CString strFromINI, BOOL &bAttri, CButton &btnCtrl);
	/**********************************************************************
	 功能描述： 初始化成员属性
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri();
	/**********************************************************************
	 功能描述： 初始化成员属性，不包括check
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri2();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton m_checkGridLine;
	CButton m_checkStatisticInf;
	CButton m_ckeckMaxValue;
	CButton m_checkMinValue;
	CButton m_checkEffectiveValue;
	CButton m_checkMeanValue;
	afx_msg void OnBnClickedCheckGridLine();
	CButton m_checkPeakValue;
	afx_msg void OnBnClickedCheckStatisticInf();
	afx_msg void OnBnClickedCheckMaxValue();
	afx_msg void OnBnClickedCheckMinValue();
	afx_msg void OnBnClickedCheckEffectiveValue();
	afx_msg void OnBnClickedCheckMeanValue();
	afx_msg void OnBnClickedCheckPeakValue();





};
