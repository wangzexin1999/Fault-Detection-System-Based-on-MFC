// ChannelParaDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaDialog.h"
#include "afxdialogex.h"

// CChannelParaDialog 对话框

IMPLEMENT_DYNAMIC(CChannelParaDialog, CDialogEx)

CChannelParaDialog::CChannelParaDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChannelParaDialog::IDD, pParent){
}

CChannelParaDialog::~CChannelParaDialog(){}

void CChannelParaDialog::RefreshDlg(){
	m_generalParaView.GridCtrlInit();
	m_triggerParaView.GridCtrlInit();
	m_geometricParaView.GridCtrlInit();
}
void CChannelParaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_channelTab);
}

BEGIN_MESSAGE_MAP(CChannelParaDialog, CDialogEx)
	
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CChannelParaDialog::OnTcnSelchangeTab1)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CChannelParaDialog 消息处理程序

BOOL CChannelParaDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_channelTab.InsertItem(0, _T("通用参数"));
	m_channelTab.InsertItem(1, _T("触发参数"));
	m_channelTab.InsertItem(2, _T("几何参数"));
	//创建通道参数显示的试图  
	m_generalParaView.Create(IDD_DIALOG_GENERAL_PARA, &m_channelTab);
	m_triggerParaView.Create(IDD_DIALOG_TRIGGER_PARA, &m_channelTab);
	m_geometricParaView.Create(IDD_DIALOG_GEOMETRIC_PARA, &m_channelTab);
	
	//设定在Tab内显示的范围  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	//m_tabSystemPara.MoveWindow(tabRect);
	m_generalParaView.MoveWindow(&tabRect);
	m_triggerParaView.MoveWindow(&tabRect);
	m_geometricParaView.MoveWindow(&tabRect);
	//把对话框对象指针保存起来
	pDialog[0] = &m_generalParaView;
	pDialog[1] = &m_triggerParaView;
	pDialog[2] = &m_geometricParaView;
	//显示初始页面  
	m_generalParaView.ShowWindow(SW_SHOW);
	m_triggerParaView.ShowWindow(SW_HIDE);
	m_geometricParaView.ShowWindow(SW_HIDE);
	m_CurSelTab = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CChannelParaDialog::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//把当前的页面隐藏起来
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	
	m_CurSelTab = m_channelTab.GetCurSel();
	//把新的页面显示出来
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void CChannelParaDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO:  在此处添加消息处理程序代码
}
