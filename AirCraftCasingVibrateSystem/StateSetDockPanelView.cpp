// StateSetDockPanelView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StateSetDockPanelView.h"


// CStateSetDockPanelView

IMPLEMENT_DYNAMIC(CStateSetDockPanelView, CDockablePane)

CStateSetDockPanelView::CStateSetDockPanelView()
{

}

CStateSetDockPanelView::~CStateSetDockPanelView()
{
}


BEGIN_MESSAGE_MAP(CStateSetDockPanelView, CDockablePane)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CStateSetDockPanelView ��Ϣ�������


void CStateSetDockPanelView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDockablePane::OnPaint()
	CRect rect;
	CBrush  bush;

	GetClientRect(rect);
	bush.CreateSolidBrush(RGB(240, 240, 240));
	dc.FillRect(&rect, &bush);
}


int CStateSetDockPanelView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	if (!(m_stateSetDialog.Create(IDD_DIALOG_STATE_SET, this)))
	{
		TRACE0("δ��״̬����");
		return -1;
	}

	m_stateSetDialog.ShowWindow(SW_SHOW);
	return 0;
}
void CStateSetDockPanelView::RefreshView(){
	m_stateSetDialog.RefreshView();
}