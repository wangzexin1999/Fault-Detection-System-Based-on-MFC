// SystemParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SystemParaView.h"


// CSystemParaView

IMPLEMENT_DYNAMIC(CSystemParaView, CDockablePane)

CSystemParaView::CSystemParaView()
{

}

CSystemParaView::~CSystemParaView()
{
}


BEGIN_MESSAGE_MAP(CSystemParaView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CSystemParaView 消息处理程序




int CSystemParaView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if (!m_systemParaDialog.Create(IDD_DIALOG_SYSTEM_PARA,this))
	{
		TRACE0("未能创建参数设置");
		return -1;
	}
	m_systemParaDialog.ShowWindow(SW_SHOW);
	return 0;
}


void CSystemParaView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	//if (m_systemParaDialog.GetSafeHwnd())
	//{
	//	
	//	/*CRect tabRect;
	//	m_systemParaDialog.GetClientRect(tabRect);
	//	tabRect.DeflateRect(10, 10);
	//	m_systemParaDialog.m_tabSystemPara.MoveWindow(tabRect);*/
	//	CRect rect;
	//	GetClientRect(rect);
	//	//m_systemParaDialog.m_tabSystemPara.MoveWindow(rect);
	//	m_systemParaDialog.MoveWindow(rect);
	//	/*m_systemParaDialog.m_sersorPara.MoveWindow(&rect);
	//	m_systemParaDialog.m_devicePara.MoveWindow(&rect);*/
	//}
	// TODO:  在此处添加消息处理程序代码
}
