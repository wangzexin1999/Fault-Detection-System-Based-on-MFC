// GraphicAttributeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GraphicAttributeView.h"
#include "afxdialogex.h"


// CGraphicAttributeView �Ի���

IMPLEMENT_DYNAMIC(CGraphicAttributeView, CDialogEx)

CGraphicAttributeView::CGraphicAttributeView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphicAttributeView::IDD, pParent)
{

}

CGraphicAttributeView::~CGraphicAttributeView()
{
}

void CGraphicAttributeView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGraphicAttributeView, CDialogEx)
END_MESSAGE_MAP()


// CGraphicAttributeView ��Ϣ�������
