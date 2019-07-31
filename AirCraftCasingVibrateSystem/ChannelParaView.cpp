// ChannelParaView.cpp : ʵ���ļ�
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



// CChannelParaView ��Ϣ�������




void CChannelParaView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDockablePane::OnPaint()
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
	//m_tab.Create(CMFCTabCtrl::STYLE_3D_ONENOTE,//�ؼ���ʽ��������������ʾ 
	//	rectTree,//�ؼ�����
	//	this,//�ؼ��ĸ�����ָ��
	//	10,//�ؼ�ID
	//	CMFCTabCtrl::LOCATION_TOP);//��ǩλ��	
	//m_tab.AutoSizeWindow(TRUE);//�����öԻ�����tab��ʾ��������ţ�ͬʱ�����Ի����OnSize��Ϣ


	// TODO:  �ڴ������ר�õĴ�������
	/*if (!m_devicePara.Create(IDD_DIALOG_DEVICE_PARA, this))
	{
		TRACE0("δ�ܴ�����������");
		return -1;
	}
	m_devicePara.ShowWindow(SW_SHOW);*/
	if (!m_channelParaDialog.Create(IDD_DIALOG_CHANNEL_PARA, this))
	{
		TRACE0("δ��ͨ����������");
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

	// TODO:  �ڴ˴������Ϣ����������
   
}
