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

// 窗口背景
void CColorView::OnBnClickedMfcbuttonWinBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colBKColor = GetColorDiag();
	SetMFCButtonColor(m_windowBGColor, m_colBKColor);
}

// 图形区域背景
void CColorView::OnBnClickedMfcbuttonGraphBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colGBKColor = GetColorDiag();
	SetMFCButtonColor(m_graphBGColor, m_colGBKColor);
}

// 信息窗背景
void CColorView::OnBnClickedMfcbuttonInfBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colTBKColor = GetColorDiag();
	SetMFCButtonColor(m_infWinBGColor, m_colTBKColor);
}

// 曲线1
void CColorView::OnBnClickedMfcbuttonSeris1Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colSerie[0] = GetColorDiag();
	SetMFCButtonColor(m_series1Color, m_colSerie[0]);
}

// 曲线2
void CColorView::OnBnClickedMfcbuttonSeris2Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colSerie[1] = GetColorDiag();
	SetMFCButtonColor(m_series2Color, m_colSerie[1]);
}

// 曲线3
void CColorView::OnBnClickedMfcbuttonSeris33Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colSerie[2] = GetColorDiag();
	SetMFCButtonColor(m_series3Color, m_colSerie[2]);
}

// 曲线4
void CColorView::OnBnClickedMfcbuttonSeris4Bg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colSerie[3] = GetColorDiag();
	SetMFCButtonColor(m_series4Color, m_colSerie[3]);
}

// 网络
void CColorView::OnBnClickedMfcbuttonGridBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colGridLineColor = GetColorDiag();
	SetMFCButtonColor(m_gridColor, m_colGridLineColor);
}

// 坐标
void CColorView::OnBnClickedMfcbuttonCoorBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colCoorColor = GetColorDiag();
	SetMFCButtonColor(m_coordinateColor, m_colCoorColor);
}

//刻度
void CColorView::OnBnClickedMfcbuttonScaleBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colScale = GetColorDiag();
	SetMFCButtonColor(m_scaleColor, m_colScale);
}

//光标
void CColorView::OnBnClickedMfcbuttonCurlorBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colCursor1 = GetColorDiag();
	SetMFCButtonColor(m_cursorColor, m_colCursor1);
}

//X轴
void CColorView::OnBnClickedMfcbuttonXBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colXCoor = GetColorDiag();
	SetMFCButtonColor(m_xAxisColor, m_colBKColor);
}

//Y轴
void CColorView::OnBnClickedMfcbuttonYBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colYCoor = GetColorDiag();
	SetMFCButtonColor(m_yAxisColor, m_colYCoor);
}

// 统计信息
void CColorView::OnBnClickedMfcbuttonStatiscBg()
{
	// TODO:  在此添加控件通知处理程序代码
	m_colStatisticInf = GetColorDiag();
	SetMFCButtonColor(m_statisticsInfColor, m_colStatisticInf);
	
}

//获得用户选择的颜色
COLORREF CColorView::GetColorDiag()
{

	COLORREF color = RGB(255, 0, 0);      // 颜色对话框的初始颜色为红色  
	CColorDialog colorDlg(color);
	colorDlg.DoModal();

	return colorDlg.GetColor();
}

// 设置按钮颜色
void CColorView::SetMFCButtonColor(CMFCButton & btn, COLORREF color)
{
	btn.SetFaceColor(color);//设置颜色
	btn.m_bTransparent = FALSE;//设置不透明
	btn.m_bDontUseWinXPTheme = TRUE;//设置不适用xp主题
	btn.m_bDrawFocus = FALSE;//设置聚焦线
	btn.SetFocus();
	btn.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;//设置Win10扁平效果
	
}

BOOL CColorView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 加载默认颜色
	 m_colSerie[0] = RGB(255,0,0);					       // 曲线颜色
	 m_colBKColor = RGB(192, 192, 192);                    // 背景颜色
	 m_colGBKColor = RGB(255, 255, 255);                   // 图形区背景颜色
	 m_colTBKColor = RGB(192, 192, 192);                   // 信息窗背景颜色
	 m_colGridLineColor = RGB(192, 192, 192);              // 网格线颜色
	 m_colCoorColor = RGB(0, 64, 128);                  // 坐标轴颜色
	 m_colCursor1 = RGB(0, 0, 255);                    // 光标1颜色
	 m_colCursor2 = RGB(0, 0, 255);                    // 光标2颜色
	 m_colScale = RGB(128, 0, 64);						// 刻度颜色
	 m_colXCoor = RGB(128, 0, 128);						// X坐标颜色
	 m_colYCoor = RGB(128, 0, 128);						// Y坐标颜色
	 m_colStatisticInf = RGB(192, 192, 192);               // 统计信息颜色

	 // 设置按钮默认颜色
	 SetMFCButtonColor(m_series1Color, m_colSerie[0]);
	 SetMFCButtonColor(m_windowBGColor, m_colBKColor);
	 SetMFCButtonColor(m_graphBGColor, m_colGBKColor);
	 SetMFCButtonColor(m_infWinBGColor, m_colTBKColor);
	 SetMFCButtonColor(m_gridColor, m_colGridLineColor);
	 SetMFCButtonColor(m_coordinateColor, m_colCoorColor);
	 SetMFCButtonColor(m_cursorColor, m_colCursor1);
	 SetMFCButtonColor(m_cursorColor, m_colCursor2);
	 SetMFCButtonColor(m_scaleColor, m_colScale);
	 SetMFCButtonColor(m_xAxisColor, m_colXCoor);
	 SetMFCButtonColor(m_yAxisColor, m_colYCoor);
	 SetMFCButtonColor(m_statisticsInfColor, m_colStatisticInf);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
