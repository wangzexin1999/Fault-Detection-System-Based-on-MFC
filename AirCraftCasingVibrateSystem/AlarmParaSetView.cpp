// AlarmParaSetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "AlarmParaSetView.h"
#include "afxdialogex.h"


// CAlarmParaSetView 对话框

IMPLEMENT_DYNAMIC(CAlarmParaSetView, CDialogEx)

CAlarmParaSetView::CAlarmParaSetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAlarmParaSetView::IDD, pParent)
{

}

CAlarmParaSetView::~CAlarmParaSetView()
{
}

void CAlarmParaSetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAlarmParaSetView, CDialogEx)
END_MESSAGE_MAP()


// CAlarmParaSetView 消息处理程序
