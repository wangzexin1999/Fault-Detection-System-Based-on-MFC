// GraphicAttributeView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GraphicAttributeView.h"
#include "afxdialogex.h"


// CGraphicAttributeView 对话框

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


// CGraphicAttributeView 消息处理程序
