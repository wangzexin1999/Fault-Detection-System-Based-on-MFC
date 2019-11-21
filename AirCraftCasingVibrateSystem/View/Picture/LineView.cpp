// LineView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "LineView.h"
#include "afxdialogex.h"


// CLineView 对话框

IMPLEMENT_DYNAMIC(CLineView, CDialogEx)

CLineView::CLineView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLineView::IDD, pParent)
{

}

CLineView::~CLineView()
{
}

void CLineView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLineView, CDialogEx)
END_MESSAGE_MAP()


// CLineView 消息处理程序
