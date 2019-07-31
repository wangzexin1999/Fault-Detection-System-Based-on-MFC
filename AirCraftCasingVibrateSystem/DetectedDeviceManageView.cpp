// DetectedDeviceManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DetectedDeviceManageView.h"
#include "afxdialogex.h"


// CDetectedDeviceManageView 对话框

IMPLEMENT_DYNAMIC(CDetectedDeviceManageView, CDialogEx)

CDetectedDeviceManageView::CDetectedDeviceManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDetectedDeviceManageView::IDD, pParent)
{

}

CDetectedDeviceManageView::~CDetectedDeviceManageView()
{
}

void CDetectedDeviceManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDetectedDeviceManageView, CDialogEx)
END_MESSAGE_MAP()


// CDetectedDeviceManageView 消息处理程序
