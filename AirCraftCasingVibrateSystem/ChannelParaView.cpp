// ChannelParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaView.h"


// CChannelParaView

IMPLEMENT_DYNAMIC(CChannelParaView, CDockablePane)

CChannelParaView::CChannelParaView()
{

}

CChannelParaView::~CChannelParaView()
{
}


BEGIN_MESSAGE_MAP(CChannelParaView, CDockablePane)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CChannelParaView 消息处理程序




void CChannelParaView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDockablePane::OnPaint()
	/*CRect rectTree;
	GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));*/


	/*CRect rectTree;
	this->GetWindowRect(rectTree);
	m_tab.MoveWindow(rectTree);*/

	CRect rect;
	CBrush  bush;

	GetClientRect(rect);
	bush.CreateSolidBrush(RGB(240,240,240));
	dc.FillRect(&rect, &bush);
	
}


int CChannelParaView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	//CRect rectTree;
	//this->GetWindowRect(rectTree);
	//m_tab.Create(CMFCTabCtrl::STYLE_3D_ONENOTE,//控件样式，如最上面所演示 
	//	rectTree,//控件区域
	//	this,//控件的父窗口指针
	//	10,//控件ID
	//	CMFCTabCtrl::LOCATION_TOP);//标签位置	
	//m_tab.AutoSizeWindow(TRUE);//可以让对话框随tab显示区域而缩放，同时出发对话框的OnSize消息


	// TODO:  在此添加您专用的创建代码
	/*if (!m_devicePara.Create(IDD_DIALOG_DEVICE_PARA, this))
	{
		TRACE0("未能创建参数设置");
		return -1;
	}
	m_devicePara.ShowWindow(SW_SHOW);*/
	if (!m_channelParaDialog.Create(IDD_DIALOG_CHANNEL_PARA, this))
	{
		TRACE0("未能通道参数设置");
		return -1;
	}
	
	m_channelParaDialog.ShowWindow(SW_SHOW);
	return 0;
}


void CChannelParaView::OnSize(UINT nType, int cx, int cy)
{
	/*CRect rectTree;
	GetWindowRect(rectTree);
	m_channelParaDialog.MoveWindow(rectTree);*/
	CDockablePane::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
   
}
