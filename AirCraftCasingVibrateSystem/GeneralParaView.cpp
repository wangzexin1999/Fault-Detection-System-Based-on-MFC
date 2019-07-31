// GeneralParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"


// CGeneralParaView 对话框

IMPLEMENT_DYNAMIC(CGeneralParaView, CDialogEx)

CGeneralParaView::CGeneralParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeneralParaView::IDD, pParent)
{

}

CGeneralParaView::~CGeneralParaView()
{
}

void CGeneralParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_GENERAL_PARA, m_generalParaList);
}


BEGIN_MESSAGE_MAP(CGeneralParaView, CDialogEx)
END_MESSAGE_MAP()


// CGeneralParaView 消息处理程序


BOOL CGeneralParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 初始化列表
	m_generalParaList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	CRect rect;
	m_generalParaList.GetClientRect(rect);
	int nWidth = rect.Width();
	int arr[][3] = {
		0, LVCFMT_CENTER, (UINT)(10 / 50.0 * 4),
		1, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		2, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		3, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		4, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		5, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		6, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
	};
	CStringArray strArray;
	strArray.Add(_T(""));
	strArray.Add(_T("通道号"));
	strArray.Add(_T("通道状态"));
	strArray.Add(_T("测量类型"));
	strArray.Add(_T("通道描述"));
	strArray.Add(_T("窗类型"));
	strArray.Add(_T("窗宽"));	
	for (int i = 0; i < 7; i++)
	{
		m_generalParaList.InsertColumn(arr[i][0], strArray.GetAt(i), arr[i][1], arr[i][2]);
	}


	/*for (int i = 0; i < length; i++)
	{

	}*/
	m_generalParaList.InsertItem(0, _T(""));   //第一行，第一列
	m_generalParaList.SetItemText(0, 1, _T("1-1"));//第一行，第二列
	m_generalParaList.SetItemText(0, 2, _T("NO"));
	m_generalParaList.SetItemText(0, 3, _T("电压测量"));
	m_generalParaList.SetItemText(0, 4, _T("水平"));
	m_generalParaList.SetItemText(0, 5, _T("矩形窗"));

	m_generalParaList.InsertItem(1, _T(""));   //第二行，第一列
	m_generalParaList.SetItemText(1, 1, _T("1-2"));//第一行，第二列
	m_generalParaList.SetItemText(1, 2, _T("NO"));
	m_generalParaList.SetItemText(1, 3, _T("电压测量"));
	m_generalParaList.SetItemText(1, 4, _T("垂直"));
	m_generalParaList.SetItemText(1, 5, _T("矩形窗"));

	m_generalParaList.InsertItem(2, _T(""));   //第二行，第一列
	m_generalParaList.SetItemText(2, 1, _T("1-3"));//第一行，第二列
	m_generalParaList.SetItemText(2, 2, _T("NO"));
	m_generalParaList.SetItemText(2, 3, _T("电压测量"));
	m_generalParaList.SetItemText(2, 4, _T("增压泵"));
	m_generalParaList.SetItemText(2, 5, _T("矩形窗"));


	m_generalParaList.InsertItem(3, _T(""));   //第二行，第一列
	m_generalParaList.SetItemText(3, 1, _T("1-4"));//第一行，第二列
	m_generalParaList.SetItemText(3, 2, _T("NO"));//第二行，第二列
	m_generalParaList.SetItemText(3, 3, _T("电压测量"));
	m_generalParaList.SetItemText(3, 4, _T("喷口泵"));
	m_generalParaList.SetItemText(3, 5, _T("矩形窗"));

	m_generalParaList.InsertItem(4, _T(""));   //第二行，第一列
	m_generalParaList.SetItemText(4, 1, _T("1-5"));//第二行，第二列
	m_generalParaList.SetItemText(4, 2, _T("NO"));//第二行，第二列
	m_generalParaList.SetItemText(4, 3, _T("电压测量"));
	m_generalParaList.SetItemText(4, 4, _T("主泵"));
	m_generalParaList.SetItemText(4, 5, _T("矩形窗"));

	m_generalParaList.InsertItem(5, _T(""));   //第二行，第一列
	m_generalParaList.SetItemText(5, 1, _T("1-6"));//第二行，第二列
	m_generalParaList.SetItemText(5, 2, _T("NO"));//第二行，第二列
	m_generalParaList.SetItemText(5, 3, _T("电压测量"));
	m_generalParaList.SetItemText(5, 4, _T("备用"));
	m_generalParaList.SetItemText(5, 5, _T("矩形窗"));
	


	LOGFONT   logfont;//最好弄成类成员,全局变量,静态成员  
	CFont   *pfont1 = m_generalParaList.GetFont();
	pfont1->GetLogFont(&logfont);
	logfont.lfHeight = logfont.lfHeight * 1.3;   //这里可以修改字体的高比例
	logfont.lfWidth = logfont.lfWidth * 1.3;   //这里可以修改字体的宽比例
	static   CFont   font1;
	font1.CreateFontIndirect(&logfont);
	m_generalParaList.SetFont(&font1);
	font1.Detach();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
