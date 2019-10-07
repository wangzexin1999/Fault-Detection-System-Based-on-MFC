// CollectionPlanManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionPlanManageView.h"
#include "afxdialogex.h"


// CollectionPlanManageView 对话框

IMPLEMENT_DYNAMIC(CollectionPlanManageView, CDialogEx)

CollectionPlanManageView::CollectionPlanManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CollectionPlanManageView::IDD, pParent)
{

}

CollectionPlanManageView::~CollectionPlanManageView()
{
}

void CollectionPlanManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CollectionPlanManageView, CDialogEx)
END_MESSAGE_MAP()


// CollectionPlanManageView 消息处理程序
