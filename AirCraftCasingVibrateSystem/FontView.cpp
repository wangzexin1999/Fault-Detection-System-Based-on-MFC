// FontView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FontView.h"
#include "afxdialogex.h"


// CFontView 对话框

IMPLEMENT_DYNAMIC(CFontView, CDialogEx)

CFontView::CFontView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFontView::IDD, pParent)
{

}

CFontView::~CFontView()
{
}

void CFontView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_XCOOR, m_xCoor);
	DDX_Control(pDX, IDC_BUTTON_YCOOR, m_yCoor);
	DDX_Control(pDX, IDC_BUTTON_CURSOR_VALUE, m_cursorValue);
	DDX_Control(pDX, IDC_BUTTON_X_UNIT, m_xUnit);
	DDX_Control(pDX, IDC_BUTTON_Y_UNIT, m_yUnit);
	DDX_Control(pDX, IDC_BUTTON_CURSOR_MARK, m_cursorMark);
	DDX_Control(pDX, IDC_BUTTON_STATISTIS_INF, m_statisticInf);
	DDX_Control(pDX, IDC_BUTTON_TEXT_INF, m_textNote);
	DDX_Control(pDX, IDC_BUTTON_PROJECT_INF, m_projectInf);
}


BEGIN_MESSAGE_MAP(CFontView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_XCOOR, &CFontView::OnBnClickedButtonXcoor)
	ON_BN_CLICKED(IDC_BUTTON_YCOOR, &CFontView::OnBnClickedButtonYcoor)
	ON_BN_CLICKED(IDC_BUTTON_CURSOR_VALUE, &CFontView::OnBnClickedButtonCursorValue)
	ON_BN_CLICKED(IDC_BUTTON_X_UNIT, &CFontView::OnBnClickedButtonXUnit)
	ON_BN_CLICKED(IDC_BUTTON_Y_UNIT, &CFontView::OnBnClickedButtonYUnit)
	ON_BN_CLICKED(IDC_BUTTON_CURSOR_MARK, &CFontView::OnBnClickedButtonCursorMark)
	ON_BN_CLICKED(IDC_BUTTON_STATISTIS_INF, &CFontView::OnBnClickedButtonStatistisInf)
	ON_BN_CLICKED(IDC_BUTTON_TEXT_INF, &CFontView::OnBnClickedButtonTextInf)
	ON_BN_CLICKED(IDC_BUTTON_PROJECT_INF, &CFontView::OnBnClickedButtonProjectInf)
END_MESSAGE_MAP()


// CFontView 消息处理程序


BOOL CFontView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


// X 轴
void CFontView::OnBnClickedButtonXcoor()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontXCoor = m_fontDlg.m_cf.lpLogFont;
	}
	
	
}

// Y轴
void CFontView::OnBnClickedButtonYcoor()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontYCoor = m_fontDlg.m_cf.lpLogFont;
	}
}

// 光标读数
void CFontView::OnBnClickedButtonCursorValue()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontXCoor = m_fontDlg.m_cf.lpLogFont;
	}
}

// X轴单位
void CFontView::OnBnClickedButtonXUnit()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontXUnit = m_fontDlg.m_cf.lpLogFont;
	}
}

// Y轴单位
void CFontView::OnBnClickedButtonYUnit()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontYUnit = m_fontDlg.m_cf.lpLogFont;
	}
}

// 光标标注
void CFontView::OnBnClickedButtonCursorMark()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontCursorValue = m_fontDlg.m_cf.lpLogFont;
	}
}

//统计信息
void CFontView::OnBnClickedButtonStatistisInf()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontStaValue = m_fontDlg.m_cf.lpLogFont;
	}
}

// 文本注释
void CFontView::OnBnClickedButtonTextInf()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontLegend = m_fontDlg.m_cf.lpLogFont;
	}
}

// 工程信息
void CFontView::OnBnClickedButtonProjectInf()
{
	// TODO:  在此添加控件通知处理程序代码
	if (IDOK == m_fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，则获取被选择字体的名称并显示到编辑框里   
		m_lFontLegend = m_fontDlg.m_cf.lpLogFont;
	}
}


