// ColorView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ColorView.h"
#include "afxdialogex.h"


// CColorView 对话框

IMPLEMENT_DYNAMIC(CColorView, CDialogEx)

CColorView::CColorView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorView::IDD, pParent)
{

}

CColorView::~CColorView()
{
}

void CColorView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_WIN_BG, m_windowBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_GRAPH_BG, m_graphBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_INF_BG, m_infWinBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS1_BG, m_series1Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS2_BG, m_series2Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS33_BG, m_series3Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS4_BG, m_series4Color);
	DDX_Control(pDX, IDC_MFCBUTTON_GRID_BG, m_gridColor);
	DDX_Control(pDX, IDC_MFCBUTTON_COOR_BG, m_coordinateColor);
	DDX_Control(pDX, IDC_MFCBUTTON_SCALE_BG, m_scaleColor);
	DDX_Control(pDX, IDC_MFCBUTTON_CURLOR_BG, m_cursorColor);
	DDX_Control(pDX, IDC_MFCBUTTON_X_BG, m_xAxisColor);
	DDX_Control(pDX, IDC_MFCBUTTON_Y_BG, m_yAxisColor);
	DDX_Control(pDX, IDC_MFCBUTTON_STATISC_BG, m_statisticsInfColor);
}


BEGIN_MESSAGE_MAP(CColorView, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON_WIN_BG, &CColorView::OnBnClickedMfcbuttonWinBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_GRAPH_BG, &CColorView::OnBnClickedMfcbuttonGraphBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_INF_BG, &CColorView::OnBnClickedMfcbuttonInfBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS1_BG, &CColorView::OnBnClickedMfcbuttonSeris1Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS2_BG, &CColorView::OnBnClickedMfcbuttonSeris2Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS33_BG, &CColorView::OnBnClickedMfcbuttonSeris33Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS4_BG, &CColorView::OnBnClickedMfcbuttonSeris4Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_GRID_BG, &CColorView::OnBnClickedMfcbuttonGridBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_COOR_BG, &CColorView::OnBnClickedMfcbuttonCoorBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SCALE_BG, &CColorView::OnBnClickedMfcbuttonScaleBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_CURLOR_BG, &CColorView::OnBnClickedMfcbuttonCurlorBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_X_BG, &CColorView::OnBnClickedMfcbuttonXBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_Y_BG, &CColorView::OnBnClickedMfcbuttonYBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_STATISC_BG, &CColorView::OnBnClickedMfcbuttonStatiscBg)
END_MESSAGE_MAP()


// CColorView 消息处理程序


void CColorView::OnBnClickedMfcbuttonWinBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonGraphBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonInfBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonSeris1Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonSeris2Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonSeris33Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonSeris4Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonGridBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonCoorBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonScaleBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonCurlorBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonXBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonYBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::OnBnClickedMfcbuttonStatiscBg()
{
	// TODO:  在此添加控件通知处理程序代码
	ColorDiag();
}


void CColorView::ColorDiag()
{

	COLORREF color = RGB(255, 0, 0);      // 颜色对话框的初始颜色为红色  
	CColorDialog colorDlg(color);
	colorDlg.DoModal();


}