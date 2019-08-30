// ProductManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProductManageView.h"
#include "afxdialogex.h"


// CProductManageView 对话框

IMPLEMENT_DYNAMIC(CProductManageView, CDialogEx)

CProductManageView::CProductManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProductManageView::IDD, pParent)
{

}

CProductManageView::~CProductManageView()
{
}

void CProductManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProductManageView, CDialogEx)
END_MESSAGE_MAP()


// CProductManageView 消息处理程序
