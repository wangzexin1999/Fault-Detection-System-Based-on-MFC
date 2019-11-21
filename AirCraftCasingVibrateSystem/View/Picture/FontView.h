/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： CFontView.h
内容摘要： 属性设置的字体设置，对应的实现类文件为CFontView.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-09-17
完成日期:
History:
1. Date:    2018-09-17         Author:刘望
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include "afxwin.h"


// 字体的属性设置
struct  FontAttri
{
	LOGFONT m_lFont; // 字体名字
	int m_lFontSize;  // 字体大小
};


// CFontView 对话框

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)
public:
	FontAttri m_lFontXCoor; //x轴
	FontAttri m_lFontYCoor; // y轴
	FontAttri m_lFontXUnit; // x单位
	FontAttri m_lFontYUnit; //y单位
	FontAttri m_lFontCursorValue; // 光标
	FontAttri m_lFontStaValue;  // 统计信息
	FontAttri m_lFontLegend;   // 图例

	CString m_font = "font";
public:
	CFontView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFontView();

// 对话框数据
	enum { IDD = IDD_DIALOG_FONT };

public:
	/**********************************************************************
	 功能描述： 初始化字体控件的默认选项
	 输入参数：
	 输出参数： 
	 返 回 值： LOGFONT ---字体默认设置
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	LOGFONT InitFontDialog();
	/**********************************************************************
	 功能描述：初始化字体 
	 输入参数： fonAttri --字体；strInput--从配置文件读出的字符串
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitFont(FontAttri &fonAttri,CString strInput);
	/**********************************************************************
	 功能描述： 初始化成员函数
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_xCoor;
	CButton m_yCoor;
	CButton m_cursorValue;
	CButton m_xUnit;
	CButton m_yUnit;
	CButton m_cursorMark;
	CButton m_statisticInf;
	CButton m_textNote;
	CButton m_projectInf;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonXcoor();
	afx_msg void OnBnClickedButtonYcoor();
	afx_msg void OnBnClickedButtonCursorValue();
	afx_msg void OnBnClickedButtonXUnit();
	afx_msg void OnBnClickedButtonYUnit();
	afx_msg void OnBnClickedButtonCursorMark();
	afx_msg void OnBnClickedButtonStatistisInf();
	afx_msg void OnBnClickedButtonTextInf();
	afx_msg void OnBnClickedButtonProjectInf();
};
