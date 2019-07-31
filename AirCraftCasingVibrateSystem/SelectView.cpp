// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SelectView.h"
#include "afxdialogex.h"


// CSelectView 对话框

IMPLEMENT_DYNAMIC(CSelectView, CDialogEx)

CSelectView::CSelectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectView::IDD, pParent)
{

}

CSelectView::~CSelectView()
{
}

void CSelectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectView, CDialogEx)
END_MESSAGE_MAP()


// CSelectView 消息处理程序
