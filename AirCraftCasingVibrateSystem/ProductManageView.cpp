// ProductManageView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProductManageView.h"
#include "afxdialogex.h"


// CProductManageView �Ի���

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


// CProductManageView ��Ϣ�������
