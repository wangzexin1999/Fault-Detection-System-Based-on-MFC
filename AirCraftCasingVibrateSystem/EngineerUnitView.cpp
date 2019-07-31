// EngineerUnitView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "EngineerUnitView.h"
#include "afxdialogex.h"


// CEngineerUnitView 对话框

IMPLEMENT_DYNAMIC(CEngineerUnitView, CDialogEx)

CEngineerUnitView::CEngineerUnitView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEngineerUnitView::IDD, pParent)
{

}

CEngineerUnitView::~CEngineerUnitView()
{
}

void CEngineerUnitView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEngineerUnitView, CDialogEx)
END_MESSAGE_MAP()


// CEngineerUnitView 消息处理程序
