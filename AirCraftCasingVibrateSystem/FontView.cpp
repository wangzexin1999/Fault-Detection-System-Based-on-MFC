// FontView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FontView.h"
#include "afxdialogex.h"


// CFontView 对话框

IMPLEMENT_DYNAMIC(CFontView, CDialogEx)

CFontView::CFontView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFontView::IDD, pParent)
{

}

CFontView::~CFontView()
{
}

void CFontView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFontView, CDialogEx)
END_MESSAGE_MAP()


// CFontView 消息处理程序
