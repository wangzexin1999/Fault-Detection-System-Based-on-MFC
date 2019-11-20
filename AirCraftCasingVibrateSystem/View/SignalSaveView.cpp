// SignalSaveView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalSaveView.h"
#include "afxdialogex.h"


// CSignalSaveView 对话框

IMPLEMENT_DYNAMIC(CSignalSaveView, CDialogEx)

CSignalSaveView::CSignalSaveView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalSaveView::IDD, pParent)
{

}

CSignalSaveView::~CSignalSaveView()
{
}

void CSignalSaveView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignalSaveView, CDialogEx)
END_MESSAGE_MAP()


// CSignalSaveView 消息处理程序
