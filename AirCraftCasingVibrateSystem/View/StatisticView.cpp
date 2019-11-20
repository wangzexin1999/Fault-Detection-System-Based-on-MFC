// StatisticView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StatisticView.h"
#include "afxdialogex.h"


// CStatisticView 对话框

IMPLEMENT_DYNAMIC(CStatisticView, CDialogEx)

CStatisticView::CStatisticView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStatisticView::IDD, pParent)
{

}

CStatisticView::~CStatisticView()
{
}

void CStatisticView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStatisticView, CDialogEx)
END_MESSAGE_MAP()


// CStatisticView 消息处理程序
