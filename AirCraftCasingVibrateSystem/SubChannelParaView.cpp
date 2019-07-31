// SubChannelParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SubChannelParaView.h"
#include "afxdialogex.h"


// CSubChannelParaView 对话框

IMPLEMENT_DYNAMIC(CSubChannelParaView, CDialogEx)

CSubChannelParaView::CSubChannelParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubChannelParaView::IDD, pParent)
{

}

CSubChannelParaView::~CSubChannelParaView()
{
}

void CSubChannelParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubChannelParaView, CDialogEx)
END_MESSAGE_MAP()


// CSubChannelParaView 消息处理程序
