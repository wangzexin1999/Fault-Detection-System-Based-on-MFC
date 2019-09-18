// FontView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FontView.h"
#include "afxdialogex.h"

#include "FileUtil.h"
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
	InitAttri(); // 初始化成员变量，字体名，字体大小
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


// X 轴
void CFontView::OnBnClickedButtonXcoor()
{
	// TODO:  在此添加控件通知处理程序代码
	

	// 构造字体对话框，初始选择字体名为“宋体”   
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，  
		m_lFontXCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXCoor.m_lFontSize = fontDlg.GetSize();
	}
	
	
}

// Y轴
void CFontView::OnBnClickedButtonYcoor()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，  
		m_lFontYCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontYCoor.m_lFontSize = fontDlg.GetSize();
	}
}

// 光标读数
void CFontView::OnBnClickedButtonCursorValue()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，  
		m_lFontXCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXCoor.m_lFontSize = fontDlg.GetSize();
	}
}

// X轴单位
void CFontView::OnBnClickedButtonXUnit()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());

	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮， 
		m_lFontXUnit.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXUnit.m_lFontSize = fontDlg.GetSize();
	}
}

// Y轴单位
void CFontView::OnBnClickedButtonYUnit()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，
		m_lFontYUnit.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontYUnit.m_lFontSize = fontDlg.GetSize();
	}
}

// 光标标注
void CFontView::OnBnClickedButtonCursorMark()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮，  
		m_lFontCursorValue.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontCursorValue.m_lFontSize = fontDlg.GetSize();
	}
}

//统计信息
void CFontView::OnBnClickedButtonStatistisInf()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮， 
		m_lFontStaValue.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontStaValue.m_lFontSize = fontDlg.GetSize();
	}
}

// 文本注释
void CFontView::OnBnClickedButtonTextInf()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮， 
		m_lFontLegend.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontLegend.m_lFontSize = fontDlg.GetSize();
	}
}

// 工程信息
void CFontView::OnBnClickedButtonProjectInf()
{
	// TODO:  在此添加控件通知处理程序代码
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// 如果用户选择了字体对话框的OK按钮  
		m_lFontLegend.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontLegend.m_lFontSize = fontDlg.GetSize();
	}
}


// 字体控件得默认选择
LOGFONT CFontView::InitFontDialog()
{
	  
	LOGFONT lf;             // LOGFONT变量   
	// 将lf所有字节清零   
	memset(&lf, 0, sizeof(LOGFONT));
	// 将lf中的元素字体名设为“宋体”   
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T("宋体"));
	return lf;
}

void CFontView::InitFont(FontAttri &fonAttri, CString strInput)
{
	// 构建字体
	LOGFONT lf;             // LOGFONT变量   
	// 将lf所有字节清零   
	memset(&lf, 0, sizeof(LOGFONT));
	CString strExtractSub[] = { "", "" };
	char sepator = ',';  // 分隔符
	AfxExtractSubString(strExtractSub[0], strInput, 0, sepator);
	AfxExtractSubString(strExtractSub[1], strInput, 1, sepator);
	// 将lf中的元素字体名  
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T(strExtractSub[0]));
	fonAttri.m_lFont = lf;
	// 初始化字体大小
	fonAttri.m_lFontSize = _ttoi(strExtractSub[1]);
}


void CFontView::InitAttri()
{

	// 构建字体
	LOGFONT lf;             // LOGFONT变量   
	// 将lf所有字节清零   
	memset(&lf, 0, sizeof(LOGFONT));

	// 设置默认的字体
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "..\\IniFileNameTest.ini");  // ini 配置文件路径
	int length = 15;  // 长度
	LPSTR lpstrTemp = new char[length];
	GetPrivateProfileString(m_font, "lFontXCoor", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontXCoor, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontYCoor", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontYCoor, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontXUnit", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontXUnit, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontYUnit", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontYUnit, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontCursorValue", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontCursorValue, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontStaValue", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontStaValue, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontLegend", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontLegend, lpstrTemp);
	delete[] lpstrTemp;
	delete[] lpPath;

}