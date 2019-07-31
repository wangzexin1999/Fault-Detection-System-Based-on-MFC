// DetectDeviceManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DetectDeviceManageView.h"
#include "afxdialogex.h"


// CDetectDeviceManageView 对话框

IMPLEMENT_DYNAMIC(CDetectDeviceManageView, CDialogEx)

CDetectDeviceManageView::CDetectDeviceManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDetectDeviceManageView::IDD, pParent)
{

}

CDetectDeviceManageView::~CDetectDeviceManageView()
{
}

void CDetectDeviceManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDetectDeviceManageView, CDialogEx)
END_MESSAGE_MAP()


// CDetectDeviceManageView 消息处理程序
