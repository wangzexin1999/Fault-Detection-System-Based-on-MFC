// SystemParaDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SystemParaDialog.h"
#include "afxdialogex.h"


// CSystemParaDialog 对话框

IMPLEMENT_DYNAMIC(CSystemParaDialog, CDialogEx)

CSystemParaDialog::CSystemParaDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSystemParaDialog::IDD, pParent)
{

}

CSystemParaDialog::~CSystemParaDialog()
{
}

void CSystemParaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SYSTEM_PARA, m_tabSystemPara);
}


BEGIN_MESSAGE_MAP(CSystemParaDialog, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SYSTEM_PARA, &CSystemParaDialog::OnTcnSelchangeTabSystemPara)
END_MESSAGE_MAP()


// CSystemParaDialog 消息处理程序


BOOL CSystemParaDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//为Tab Control增加两个页面  
	m_tabSystemPara.InsertItem(0, _T("采集参数"));
	m_tabSystemPara.InsertItem(1, _T("设备参数"));
	//创建两个对话框  
	m_channelPara.Create(IDD_DIALOG_SERSOR_PARA, &m_tabSystemPara);
	m_devicePara.Create(IDD_DIALOG_DEVICE_PARA, &m_tabSystemPara);
	//设定在Tab内显示的范围  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;
	//m_tabSystemPara.MoveWindow(tabRect);
	m_channelPara.MoveWindow(&tabRect);
	m_devicePara.MoveWindow(&tabRect);
	//把对话框对象指针保存起来
	pDialog[0] = &m_channelPara;
	pDialog[1] = &m_devicePara;
	//显示初始页面  
	m_channelPara.ShowWindow(SW_SHOW);
	m_devicePara.ShowWindow(SW_HIDE);
	m_CurSelTab = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CSystemParaDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	//GetDlgItem(IDC_TAB_SYSTEM_PARA)->MoveWindow(tabRect, TRUE);
	//m_tabSystemPara.MoveWindow(tabRect);
	// TODO:  在此处添加消息处理程序代码
}


void CSystemParaDialog::OnTcnSelchangeTabSystemPara(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//把当前的页面隐藏起来
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_CurSelTab = m_tabSystemPara.GetCurSel();
	//把新的页面显示出来
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	
	*pResult = 0;
}
void CSystemParaDialog::RefreshView(){
	m_channelPara.RefreshView();
}